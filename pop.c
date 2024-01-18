#include "monty.h"

/**
 * c_pop - prints the top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/

void c_pop(stack_t **head, unsigned int line_counter)
{
    stack_t *h;

    /* Check if head is empty */
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		
		fclose(bus.file);       /* Close opened FILE */
		free(bus.content);
		
		free_stack(*head);      /* Free memory allocation */
		exit(EXIT_FAILURE);
	}
	
	/* Initialization of head to h */
	h = *head;
	
	*head = h->next;
	free(h);
}
