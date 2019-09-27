#define GLOBALS
#include "monty.h"

/**
 *openfd - opens and reads file
 *@argv: args passed to program
 *@mode: permissions given
 *Return: NULL if fail, FILE pointer if success
 */
FILE *openfd(const char *argv, const char *mode)
{

	f.fd = fopen(argv, mode);
	if (f.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	return (f.fd);
}

/**
 *main - entry point
 *@argc: number of args
 *@argv: args passed
 *Return: 0 on success -1 on failure
 */
int main(int argc, char **argv)
{
	unsigned int linenum = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f.str = NULL;
	f.fd = openfd(argv[1], "r");
	f.status = 1;
	while (f.status)
	{
		f.str = getlineAndTok();
		if (f.str == NULL)
			continue;
		linenum++;
		if (f.str)
			get_func(&head, linenum);
		free(f.str);
	}
	free(f.line_buff);
	free_dlistint(head);
	fclose(f.fd);
	return (0);
}
