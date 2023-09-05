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
	stack_t *new_node;
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
	new_node = malloc(sizeof(stack_t));

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
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * opcode_pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * opcode_pop - Removes the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * opcode_swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * opcode_add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	opcode_pop(stack, line_number);
}

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
