#include "monty.h"
vars_t vars = {NULL, NULL, NULL, 0};
/**
 * main - interpret monty code
 * @argc: Number of arguments
 * @argv: File location
 * Return: 0
 */
int main(int argc, cahr *argv[])
{
	char *par;
	FILE *file;
	size_t size = 0;
	ssize_t read_lines = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	vars.file = file;

	(if file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_lines > 0)
	{
		par = NULL;
		read_lines = getline(&par, &size, file);
		vars.content = par;
		count++;
		(if read_lines > 0)
		{
			execute(par, &stack, count, file);
		}
		free(par);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
