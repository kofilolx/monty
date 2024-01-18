#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **line_ptr, int file);
char  *clean_line(char *content);
void m_push(stack_t **head, unsigned int number);
void m_pall(stack_t **head, unsigned int number);
void m_pint(stack_t **head, unsigned int number);

extern bus_t bus;
/**
 * struct ins_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO monty project
 */
typedef struct ins_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int execute(char *content, stack_t **head, unsigned int line_counter, FILE *file);
void free_stack(stack_t *head);
void m_pop(stack_t **head, unsigned int line_counter);
void m_swap(stack_t **head, unsigned int line_counter);
void m_add(stack_t **head, unsigned int line_counter);
void m_nop(stack_t **head, unsigned int line_counter);
void m_sub(stack_t **head, unsigned int line_counter);
void m_div(stack_t **head, unsigned int line_counter);
void m_mul(stack_t **head, unsigned int line_counter);
void m_mod(stack_t **head, unsigned int line_counter);
void m_putchar(stack_t **head, unsigned int line_counter);
void m_pstr(stack_t **head, unsigned int line_counter);
void m_rotl(stack_t **head, unsigned int line_counter);
void m_rotr(stack_t **head, __attribute__((unused)) unsigned int line_counter);
void add_node(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void m_queue(stack_t **head, unsigned int line_counter);
void m_stack(stack_t **head, unsigned int line_counter);

#endif
