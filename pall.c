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

/**
 * m_pint - prints the top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/

void m_pint(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	
	printf("%d\n", (*head)->n);
}

/**
 * m_push - add node to the stack
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/

void m_push(stack_t **head, unsigned int line_counter)
{
	int n, j = 0;
	int status = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (j = 0; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				status = 1; }
		if (status == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, n);
	else
		addqueue(head, n);
}
