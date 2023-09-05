#include "monty.h"

/* Global variable for the stack (you are allowed one global variable) */
stack_t *stack = NULL;

/* Define the list of opcodes and their corresponding functions */
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

int main(int argc, char *argv[])
{
	/* Check for correct number of arguments */
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the Monty ByteCode file for reading */
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read and execute Monty instructions line by line */
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		/* Remove trailing newline character if it exists */
		if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

		/* Tokenize the instruction */
		char *opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
		{
			/* Call a function to execute the opcode */
			int found = 0; // Flag to check if opcode is found
			for (size_t i = 0; opcodes[i].opcode != NULL; i++)
			{
				if (strcmp(opcodes[i].opcode, opcode) == 0)
				{
					opcodes[i].f(&stack, line_number);
					found = 1;
					break;
				}
			}
			/* Check if opcode is not found */
			if (!found)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free(line);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
		}
	}

	/* Clean up and close the file */
	fclose(file);
	free(line);
	free_stack(&stack); // Corrected function call to free the stack

	return (EXIT_SUCCESS); // Use EXIT_SUCCESS to indicate successful execution
}
