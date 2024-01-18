#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_counter: line counter
* @file: pointer to monty file
* @content: line content
* Return: no return
*/

int execute(char *content, stack_t **stack, unsigned int line_counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", m_push}, {"pall", m_pall}, {"pint", m_pint},
				{"pop", m_pop}, {"swap", m_swap}, {"add", m_add},
				{"nop", m_nop}, {"sub", m_sub}, {"div", m_div},
                {"mul", m_mul},	{"mod", m_mod},	{"pchar", m_putchar},
				{"pstr", m_pstr}, {"rotl", m_rotl},	{"rotr", m_rotr},
				{"queue", m_queue},	{"stack", m_stack},	{NULL, NULL}
				};

	unsigned int itr = 0;
	char *ops;

	ops = strtok(content, " \n\t");
	if (ops && ops[0] == '#')
        return (0);
	bus.arg = strtok(NULL, " \n\t");
	
    while (opst[itr].opcode && ops)
	{
		if (strcmp(ops, opst[itr].opcode) == 0)
		{
            opst[itr].f(stack, line_counter);
			return (0);
		}
		itr++;
	}
	if (ops && opst[itr].opcode == NULL)
	{ 
        fprintf(stderr, "L%d: Unknown instruction %s\n", line_counter, ops);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
    }
    return (1);
}