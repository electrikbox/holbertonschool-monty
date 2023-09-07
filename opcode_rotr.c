#include "monty.h"

/**
 * opcode_rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number; // Unused parameter

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = temp->next->next;
    (*stack)->prev = NULL;
    temp->next->next = NULL;
}
