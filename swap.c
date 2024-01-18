#icnlude "monty.h"
/**
 * s_swap - swaps the top 2 elemets
 * @head: Top
 * @count: Line number
 */
void s_swap(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		fclose(vars.file);
		free(vars.content);
		free_stcak(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
}
