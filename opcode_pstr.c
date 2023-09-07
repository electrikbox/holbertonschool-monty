#include "monty.h"

/**
 * opcode_pstr - Prints the string starting at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
