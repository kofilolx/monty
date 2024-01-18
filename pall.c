#include "monty.h"

/**
 * m_pall - prints the stack
 * @head: stack head
 * @line_counter: no used
 * Return: no return
*/

void m_pall(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	(void)line_counter;

	h = *head;
	if (!h)
		return;
	
    while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}