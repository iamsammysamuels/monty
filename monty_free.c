#include "monty.h"
/**
 *
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = NULL, *curr = NULL;

	if (!*stack)
		return;
	temp = (*stack);
	while(temp->next != NULL)
	{
		curr = temp->next;
		free(temp);
		temp = curr;
	}
	free(temp);
	temp = curr = NULL;
}
