#include "monty.h"

/**
 * opcode_mod - get the modulo of the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	opcode_pop(stack, line_number);
}
