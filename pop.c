#include "monty.h"

/**
 * m_pop - prints the top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/

void m_pop(stack_t **head, unsigned int line_counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	
    free(h);
}