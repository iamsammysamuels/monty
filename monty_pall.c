#include "monty.h"

/**
 */

int monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!*stack && line_number)
		return (EXIT_FAILURE);
	temp = *stack;
	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
