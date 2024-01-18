#include "monty.h"

/**
 * m_add - adds the top two elem of the stack.
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/

void m_add(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int len;
	int tmp;
	
	len  = 0;
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n + h->next->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
