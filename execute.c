#include "monty.h"
/**
 * execute - executes opcode
 * @stack: Head
 * @counter: Counter
 * @file: Pointer to file
 * @content: Line content
 * Return: int
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops[] = {
		/*{"push", s_push},*/
		{"pall", s_pall},
		{"pint", s_pint},
		{"pop", s_pop},
	};
	unsigned int i = 0;
	char *operation;

	operation = strtok(content, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	vars.val = strtok(NULL, " \n\t");
	while (ops[i].opcode && operation)
	{
		if (strcmp(operation, ops[i].opcode) == 0)
		{
			ops[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (operation && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
