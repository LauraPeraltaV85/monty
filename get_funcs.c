#include "monty.h"
/**
 * get_func - lists of opcodes
 * @str: line in file
 * @stack: linked list
 * @line_number: line number in file
 * Return: 0
 */
void get_func(stack_t **stack, unsigned int line_number)
{
	int idx = 0;
	instruction_t option[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	while (option[idx].opcode != NULL)
	{
		if (strcmp(f.str, option[idx].opcode) == 0)
		{
			option[idx].f(stack, line_number);
			return;
		}
		idx++;
	}
	if (option[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, f.str);
		free(stack);
		free(f.str);
		free(f.num);
		fclose(f.fd);
		exit(EXIT_FAILURE);
	}
}
