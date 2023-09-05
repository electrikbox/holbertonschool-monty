#ifndef MAIN_H
#define MAIN_H
#define DELIMS " \n\t\r"

/*----------------includes----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char *data;

/*----------------structures----------------*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct monty_stack_s
{
        int n;
        struct monty_stack_s *prev;
        struct monty_stack_s *next;
} monty_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(monty_stack_t **stack, unsigned int line_number);
} instruction_t;


/*----------------prototypes----------------*/
void push(monty_stack_t **stack, unsigned int line_number);
void pall(monty_stack_t **stack, unsigned int line_number);
void freeStack(monty_stack_t **stack);

#endif
