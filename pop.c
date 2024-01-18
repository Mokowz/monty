#include "monty.h"
/**
 * s_pop - remove the top element
 * @head: Head
 * @count: Line Number
 */
void s_pop(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		fclose(vars.file);
		free(vars.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
