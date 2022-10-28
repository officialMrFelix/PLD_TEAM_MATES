#!/usr/bin/python3
"""
    This contains the FileStorage module
"""
import json
from models.base_model import BaseModel


class FileStorage():
    """
        Comment
    """
    __file_path = "file.json"
    __objects = {}

    def all(self):
        return self.__objects

    def new(self, obj):
        key = "{}.{}".format(obj.__class__.__name__, obj.id)
        self.__objects[key] = obj

    def save(self):
        obj_dict = {}

        for key, value in self.__objects.items():
            obj_dict[key] = value.to_dict()
        with open(self.__file_path, "w") as f:
            json.dump(obj_dict, f)

    def reload(self):
        try:
            with open(self.__file_path, "r") as f:
                dict_obj = json.load(f)
            for key, value in dict_obj.items():
                self.__objects[key] = eval(key.split(".")[0])(**value)
        except FileNotFoundError:
            pass
