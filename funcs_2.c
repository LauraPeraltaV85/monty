#include "monty.h"

/**
 *_add - sums the data(n) of two top nodes
 *@stack: pointer to list struct
 *@line_number: line number in file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	(*stack) = temp->next;
	free(temp);
}

#include "monty.h"

/**
 *_nop - doesn't do anything
 *@stack: pointer to list struct
 *@line_number: line number in file
 */
void _nop(__attribute__((unused))stack_t **stack,
	  __attribute__((unused))unsigned int line_number)
{
	;
}

