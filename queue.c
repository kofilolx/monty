#include "monty.h"
/**
 * m_queue - prints the top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void m_queue(stack_t **head, unsigned int line_counter)
{
	(void)head;
	(void)line_counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	
    new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	
    if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	
    if (!tmp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}