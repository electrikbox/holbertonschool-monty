#include "monty.h"

/* Function to add a new node to the stack */
void stack_push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/* Function to remove the top node from the stack */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/* Function to print all values on the stack */
void stack_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

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
