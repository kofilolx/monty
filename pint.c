#include "monty.h"
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