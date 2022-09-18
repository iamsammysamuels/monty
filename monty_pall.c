#include "monty.h"

/**
 */

int monty_pall(stack_t **stack, unsigned int line_number, token_t **tokens)
{
	stack_t *temp = NULL;

	if (!*stack)
		return (EXIT_FAILURE);
	temp = *stack;
	while (temp->next != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
