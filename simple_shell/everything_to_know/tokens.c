#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokens - splits a string and returns an array of each 
 * token/word of the string
 * @text - string to tokenize
 * @delim - delimiter(s) - only first delimiter is considered
 * @count - buffer to hold number of tokens returned by
 * function
 *
 * Return:  array of strings/tokens
 */

char **tokens(char *text, const char *delim, int *count)
{

	char **words;
	int i;
	int count_delim = 1;
	
	/*Estimate the number of tokens in view*/
	i = 0;
	while (text[i])
	{
		if (text[i] == delim[0])
			count_delim++;
		i++;
	}

	/*Allocate memory based on tokens in view*/
	words = malloc(sizeof(char *) * count_delim);

	/*Tokenize string and store in reserved array*/
	words[0] = strtok(text, delim);
	
	for (i = 1; i < count_delim; i++)
	{
		words[i] = strtok(NULL, delim);
	}

	/*Return every update*/
	*count = count_delim;
	return (words);
}

int main(void)
{
	char text[] = "This is the place where PLD TEAM MATES test their function";
	char **words;
	const char *delim = " ";
	int i = 0;
	int count = 0;

	/*Call to tokens*/
	words = tokens(text, delim, &count);
	
	/*Print all tokens/words acquired*/
	for (i = 0; i < count; i++)
	{
		printf("argument %i: %s\n", i, words[i]);
	}

	return (0);
}













