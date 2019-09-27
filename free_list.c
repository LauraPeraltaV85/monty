#include "monty.h"

/**
 *free_dlistint - frees a listint_t list
 *@head: pointer to list struct
 */
void free_dlistint(stack_t *head)
{

	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

}
