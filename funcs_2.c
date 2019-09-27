#include "monty.h"

/**
 *_add - sums the data(n) of two top nodes
 *@stack: pointer to list struct
 *@line_number: line number in file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = head;
	sum = temp + temp->n;
	head = temp->next;
	free(temp);
}
