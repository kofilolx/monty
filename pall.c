#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: stack head
 * @line_counter: number of content
 * Return: no return
*/

void c_pall(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	(void)line_counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
