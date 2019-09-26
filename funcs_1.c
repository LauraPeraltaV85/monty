#include "monty.h"

/**
 *_push - adds a node at the beginning of a list_t list
 *@stack: first element in the list
 *@line_number: int passed to function
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	char *n;
	int i;

	n = strtok(NULL, "\n\t\r ");
	for (; n[i] != '\0'; i++)
	{
		if (!isdigit(n[i]) && n[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	if (n == NULL || (!isdigit(*n) && *n != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	newnode->n = atoi(n);
	newnode->next = *stack;
	newnode->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 *_pall - prints elements in a linked list
 *@stack: pointer to first element of the list
 *@line_number: number of the line in file
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *h = *stack;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}