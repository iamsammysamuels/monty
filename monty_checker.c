#include "monty.h"

/**
 *
 *
 */

int file_check(FILE *fd)
{
	token_t *tokens;
	size_t size = 0;
	char *line = NULL, *dup_line = NULL, *temp;
	char delim[] = " \n\t\a\b";
	int sstack = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0;
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		free(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tokens = malloc(sizeof(token_t));
	if(tokens == NULL)
	{
		free(tokens);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fd) != -1)
	{
		line_number++;
		if(line_check(line, delim) == 1)
			continue;
		parse_line(line, delim, tokens, line_number, dup_line);
		if (strcmp(tokens->token_1, "stack") == 0)
			sstack = 0;
		else if (strcmp(tokens->token_1, "queue") == 0)
			sstack = 1;
		else if (strcmp(tokens->token_1, "push") == 0 && sstack == 0)
		{
			exit_status = s_push(&stack, line_number, &tokens);
			if (exit_status == EXIT_SUCCESS)
				continue;
			else
				break;
		}
		temp = tokens->token_1;
		while (strcmp(tokens->token_1, "push") != 0)
		{
			tokens->token_2 = 0;
			tokens->token_1 = "push";
		}
		tokens->token_1 = temp;
		/*else if (strcmp(tokens->token_1, "push") == 0 && sstack == 1)
		*{
			*exit_status = int q_push(&stack, line_number, &tokens);
			if (exit_status == EXIT_FAILURE)
				break;
		}*/
		exit_status = exec_line(&stack, line_number, &tokens);
		if (exit_status == EXIT_SUCCESS)
			continue;
		else
			break;
	}
	free(dup_line);
	free_stack(&stack);
	free(tokens);
	free(line);
	return (exit_status);
}

int line_check(char *line, char delim[])
{
	int p, m;

	p = m = 0;
	while (line[p])
	{
		while (delim[m])
		{
			if ( line[p] == delim[m])
				break;
			m++;
		}
		if (delim[m] == '\0')
			return (0);
		p++;
	}
	return (1);
}

void parse_line(char *line, char delim[], token_t *tokens, unsigned int line_number, char *dup_line)
{
	int nxt = 0, line_len = 0;
	char *token = NULL;

	line_len = strlen(line);
	dup_line = malloc(sizeof(char *) * line_len);
	if (dup_line == NULL)
	{
		printf("failed to alloc space to dup_line");
		exit(EXIT_FAILURE);
	}
	strcpy(dup_line, line);
	if (line_len == 0)
	{
		free(tokens);
		fprintf(stderr, "L%i: unknown instruction %s", line_number, line);
		exit(EXIT_FAILURE);
	}
	token = strtok(dup_line, delim);
	if (token == NULL)
	{
		free(tokens);
		fprintf(stderr, "L%i: unknown instruction %s", line_number, token);
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		if (nxt == 0)
		{
			tokens->token_1 = token;
		}
		else if (nxt == 1)
		{
			tokens->token_2 = token;
		}
		nxt++;
		token = strtok(NULL, delim);
	}
}
