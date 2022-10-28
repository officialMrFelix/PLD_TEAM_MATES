#!/usr/bin/python3
import models
import uuid
from datetime import datetime

"""Base Model"""


class BaseModel:
    """BaseModel Class Details"""
    def __init__(self, *args, **kwargs):

        if kwargs:
            for key, value in kwargs.items():
                if key == "created_at" or key == "updated_at":
                    value = datetime.strptime(value, "%Y-%m-%dT%H:%M:%S.%f")
                if key == "__class__":
                    continue
                setattr(self, key, value)
        else:
            self.id = str(uuid.uuid4())
            self.created_at = datetime.now()
            self.updated_at = datetime.now()
            models.storage.new(self)

    def __str__(self):
        """Prints in the form: [<class name>] (<self.id>) <self.__dict__>"""
        tmp = '[{}] ({}) {}'
        return tmp.format(self.__class__.__name__, self.id, self.__dict__)

    def save(self):
        """Updates updated_at with current time"""
        self.updated_at = datetime.now()
        models.storage.save()
        return

    def to_dict(self):
        """Return a dictionary containing all keys/values of the instance"""
        new_dictionary = self.__dict__.copy()
        new_dictionary.update({'__class__': str(self.__class__.__name__)})
        new_dictionary["created_at"] = self.created_at.isoformat()
        new_dictionary["updated_at"] = self.updated_at.isoformat()
        return new_dictionary
