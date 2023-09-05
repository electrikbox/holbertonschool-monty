#include "monty.h"

/* Function to free the stack at the end of the program */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        stack_t *temp = current;
        current = current->next;
        free(temp);
    }
    *stack = NULL;
}
