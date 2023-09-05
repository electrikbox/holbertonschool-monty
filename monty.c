#include "monty.h"

/*stack_t *stack = NULL;*/

/**
 * freeAndClose - frees memory and closes file
 * @stack: pointer to stack
 * @line: pointer to line
 * @file: pointer to file
*/
void freeAndClose(stack_t **stack, char *line, FILE *file)
{
	fclose(file);
	free(line);
	free_stack(stack);
}

/**
 * executeOp - executes given opcode
 * @opcode: opcode
 * @line_number: line number
 * @line: line
 * @file: file
 * Return: 1 if found, 0 if not
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

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
			executeOpcode(opcode, line_number, line, file);
	}
	freeAndClose(&stack, line, file);
	return (EXIT_SUCCESS);
}
