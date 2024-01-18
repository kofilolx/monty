#include "monty.h"

/**
 * m_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void m_pstr(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	(void)line_counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}