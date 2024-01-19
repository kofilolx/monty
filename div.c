#include "monty.h"
/**
 * m_div - divides the top two elements of the stack.
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void m_div(stack_t **head, unsigned int line_counter)
{
	stack_t *h;    
	int len = 0;
	int tmp;
	
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	
	h = *head;
	
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	
	tmp = h->next->n / h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}

/**
 * m_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void m_mod(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int len = 0, tmp;
	
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	tmp = h->next->n % h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
