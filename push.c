#include "monty.h"

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
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				status = 1; }
		if (status == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
