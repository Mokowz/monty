#include "monty.h"
/**
 * free_stack - free a stack
 * @head: Head
 */
void free_stack(stack_t *head)
{
	stack_t *temp;
	
	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
