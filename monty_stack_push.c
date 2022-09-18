#include "monty.h"
/**
 * s_push - pushes new node to the stack.
 * @stack: pointer to the top of the stack.
 * line_number: Current line.
 * @tokens: the data to push to stack.
 */

int s_push(stack_t **stack, unsigned int line_number, token_t **tokens)
{
	token_t *num = *tokens;
	stack_t *temp = NULL, *new_node = NULL;
	int n;

	temp = *stack;
	if (strlen(num->token_2) == 0)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	n = _atoi(num->token_2);
	if (n == INT_MIN)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = temp;
	if (temp != NULL)
		temp->prev = new_node;
	*stack = new_node;
	return (EXIT_SUCCESS);
}
