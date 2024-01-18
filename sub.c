#include "monty.h"
/**
  *m_sub- sustration
  *@head: stack head
  *@line_counter: line_number
  *Return: no return
 */
void m_sub(stack_t **head, unsigned int line_counter)
{
	stack_t *tmp;
	int suspend, nodes;

	tmp = *head;
	for (nodes = 0; tmp != NULL; nodes++)
		tmp = tmp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	suspend = tmp->next->n - tmp->n;
	tmp->next->n = suspend;
	*head = tmp->next;
	
    free(tmp);
}