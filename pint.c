#include "monty.h"
/**
 * s_pint - print top element
 * @head: Head
 * @count: Number
 */
void s_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(vars.file);
		free(vars.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
