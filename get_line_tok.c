#include "monty.h"

/**
 *getlineAndTok - getsline from file and tokenize it
 *@pFile: file received
 *Return: pointer to main
 */
char *getlineAndTok(void)
{
	char *token, *word;
	size_t line_buf_size = 0;
	int input;

	input = getline(&(f.line_buff), &line_buf_size, f.fd);

	if (input != -1)
	{
		token = strtok(f.line_buff, "\n\t\r ");
		word = token;
		return (word);
	}
	f.status = 0;
	return (NULL);
}
