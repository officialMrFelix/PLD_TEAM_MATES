#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokens - splits a string and returns an array of each
 * token/word of the string
 * @text - string to tokenize
 * @delim - delimiter(s) - can handle multiple delimiters
 * @count - buffer to hold number of tokens returned by
 * function
 *
 * Return:  array of strings/tokens. Free allocated memory after use!
 */

char **tokens(char *text, const char *delim, int *count)
{

        char **words;
        int i;
	int j;
        int count_delim = 1;

        /*Estimate the number of tokens in view*/
        i = 0;
        while (text[i])
        {
                for (j = 0; delim[j] != '\0'; j++)
		{
			if (text[i] == delim[j])
                        	count_delim++;
		}
                i++;
        }

        /*Allocate memory based on tokens in view*/
        words = malloc(sizeof(char *) * count_delim);

        /*Verify malloc was successful*/
        if (words == NULL)
        {
                printf("Malloc Failed!\n");
                exit(99);
        }

        /*Tokenize string and store in reserved array*/
        words[0] = strtok(text, delim);
        for (i = 1; i < count_delim; i++)
        {
                words[i] = strtok(NULL, delim);
        }

	/*Count tokens stored*/
	i = 0;
	count_delim = 0;
	while (words[i] != NULL)
	{
		count_delim++;
		i++;
	}

        /*Return every update*/
        *count = count_delim - 1;
        return (words);
}

int main(void)
{
	char text[] = "One two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen";
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

	/*Free allocated memories*/
	free(words);
	return (0);
}

