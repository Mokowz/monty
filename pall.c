#include "monty.h"
/**
 * s_pall - prints the stack
 * @head: Head
 * @count:Void
 */
void s_pall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
