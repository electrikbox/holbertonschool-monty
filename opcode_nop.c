#include "monty.h"

/**
 * opcode_nop - Does nothing.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
