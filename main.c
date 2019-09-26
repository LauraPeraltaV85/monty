#include "monty.h"

/**
 *openfd - opens and reads file
 *@argv: args passed to program
 *@mode: permissions given
 *Return: NULL if fail, FILE pointer if success
 */
FILE *openfd(const char *argv, const char *mode)
{
	FILE *fd;

	fd = fopen(argv, mode);
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	return (fd);
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
	char *str = NULL;
	stack_t *head = NULL;
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = openfd(argv[1], "r");
	while (fd != NULL)
	{
		str = getlineAndTok(fd);
		if (str == NULL)
			continue;
		linenum++;
		if (str)
			get_func(str, &head, linenum);
	}
	free(fd);
	free(str);
	return (0);
}
