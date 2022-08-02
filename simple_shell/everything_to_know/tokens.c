#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokens - splits a string and returns an array of each 
 * word of the string
 * @text - pointer to string
 *
 * Return:  array of strings
 */

char **tokens(char *text)
{

	char **words;
	const char *delim = " ";
	int i;
	int count_delim = 1;
	
	i = 0;
	while (text[i])
	{
		if (text[i] == delim[0])
			count_delim++;
		i++;
	}

	words = malloc(sizeof(char *) * count_delim);

	words[0] = strtok(text, delim);
	
	for (i = 1; i < count_delim; i++)
	{
		words[i] = strtok(NULL, delim);
	}

	return (words);
}

int main(void)
{
	char text[] = "something here is";
	char **words;
	const char *delim = " ";
	int i;
	int count = 1;

	for (i = 0; text[i] != '\0'; i++)
	{
		count++;
	}

	words = tokens(text);

	for (i = 0; i < count; i++)
	{
		printf("argument %i: %s\n", i, words[i]);
	}

	return (0);
}













