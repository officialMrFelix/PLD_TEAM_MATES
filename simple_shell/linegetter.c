#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * linegetter - prints "$ ", wait for the user to enter a command
 * prints it on the next line
 *
 * Return: always 0.
 */

int main(void)
{

	ssize_t n_read = 0;
	char *lineptr = NULL;
	size_t n = 0;

	/*Prompter*/
	write(1, "$ ", 2);

	/*Get user input*/
	n_read = getline(&lineptr, &n, stdin);

	printf("%s\n", lineptr);

	return (0);

}

