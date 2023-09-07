#include "monty.h"

/**
 * opcode_rotl - Rotates the stack to the top.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number; // Unused parameter

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    temp->next->next = NULL;
}
