#include "monty.h"
/**
 * s_add - add top elements
 * @head: Head
 * @count: Line number
 */
void s_add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int len = 0, data;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, count);
		fclose(vars.file);
		free(vars.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	data = temp->n + temp->next->n;
	temp->next->n = data;
	*head = temp->next;
	free(temp);
}
