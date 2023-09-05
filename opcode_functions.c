#include "monty.h"

/* Implement functions for opcode handling (push, pall, etc.) here */

/* Example push and pall functions (you will implement them fully) */

/**
 * opcode_push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    int value;

    if (arg == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    if (value == 0 && strcmp(arg, "0") != 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Create a new node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * opcode_pall - Prints all the values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; // Unused parameter

    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
