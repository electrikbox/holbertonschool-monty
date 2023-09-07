#include "monty.h"

stack_t *stack = NULL;

/**
 * executeOp - executes given opcode
 * @opcode: opcode
 * @line_number: line number
 * @line: line
 * @file: file
*/
void executeOp(char *opcode, unsigned int line_number, char *line, FILE *file)
{
	size_t i;

	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{"rotl", opcode_rotl},
		{NULL, NULL}
	};

	int found = 0;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(&stack, line_number);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		freeAndClose(&stack, line, file);
		exit(EXIT_FAILURE);
	}
}
