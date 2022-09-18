#include "monty.h"

/**
 * exec_line - compares the instruction passed with the opcodes
 * and calls the appropriate function.
 * @stack: pointer to the top of the stack.
 * @line_numbe: Current line.
 * @tokens: the data to push to stack.
 *
 * Return: returns zero on success.
 */


int exec_line(stack_t **stack, unsigned int line_number, token_t **tokens)
{
	int i = 0;
	token_t *temp;

	temp = *tokens;
	instruction_t ope[] = {
		{"pall", monty_pall},
		/*{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},*/
		{"null", NULL},
	};

	while (i < 2)
	{
		if (strcmp(ope[i].opcode, temp->token_1) == 0)
		{
			ope[i].f(stack, line_number, &tokens);
			return (EXIT_SUCCESS);
		}
		i++;
	}	
	fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, temp->token_1);
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
