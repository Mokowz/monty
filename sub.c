#include "monty.h"
/**
 * s_sub - subtract
 * @head: Top element
 * @count: Line number
 */
void s_sub(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int sub, len;

	temp = *head;
	for (len = 0; temp != NULL; len++)
		temp = temp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", count);
		fclose(vars.file);
		free(vars.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}
