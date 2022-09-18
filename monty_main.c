#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * main - The main(entry) function for monty interpreter.
 * @ac: the count for number of arguments.
 * @av: the arguments passed to the file during execution.
 *
 * Return: always zero on success.
 */

int main(int ac, char **av)
{
	int exit_status, status;
	FILE *fd;

	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", av[1]);
		return (EXIT_FAILURE);
	}
	exit_status = file_check(fd);
	status = fclose(fd);
	if (status == 0)
		exit(EXIT_FAILURE);
	else
		printf("file close error\n");
	return(exit_status);
}
