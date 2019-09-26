#include "monty.h"

/**
 *getlineAndTok - getsline from file and tokenize it
 *@pFile: file received
 *Return: pointer to main
 */
char *getlineAndTok(FILE *pFile)
{
	char *line_buff = NULL, *token, *word;
	size_t line_buf_size = 0;
	int input;

	input = getline(&line_buff, &line_buf_size, pFile);
	if (input != -1)
	{
		token = strtok(line_buff, "\n\t\r ");
		word = token;
		return (word);
	}
		free(line_buff);
	return (NULL);
}
