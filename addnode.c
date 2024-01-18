#include "monty.h"
/**
 * addnode - add node at beginning
 * @head: Head
 * @new: New
 */
void addnode(stack_t **head, int new)
{
	stack_t *newNode, *temp;

	temp = *head;
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = newNode;
	newNode->n = new;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
