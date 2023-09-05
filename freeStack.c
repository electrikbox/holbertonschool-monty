#include "main.h"

/**
 * freeStack - Frees the memory used by the stack.
 * @stack: Pointer to the top of the stack.
 */
void freeStack(monty_stack_t **stack)
{
	monty_stack_t *current = *stack, *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
