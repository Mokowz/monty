#include "monty.h"
/**
 * s_push - aadd node at beginning
 * @head: Head
 * @count: Line Number
 */
void s_push(stack_t **head, unsigned int count)
{
	int i, j = 0, fl = 0;

	if (vars.val)
	{
		if (vars.val[0] == '-')
			j++;
		for (; vars.val[j] != '\0'; j++)
		{
			if (vars.val[j] > 57 || vars.val[j] < 48)
				fl = 1;
		}
		if (fl == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(vars.file);
			free(vars.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(vars.file);
		free(vars.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(vars.val);
	if (vars.flag == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
