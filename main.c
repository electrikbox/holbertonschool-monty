#include "main.h"

char *data = NULL;

void freeAndClose(monty_stack_t **stack, FILE *file, char *line)
{
	freeStack(stack);
	free(line);
	fclose(file);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
*/
int main(int argc, char *argv[])
{
	monty_stack_t *stack = NULL;
	size_t line_number = 0, len = 0;
	FILE *file;
	int found, i;
	char *line = NULL, *opcode, *extraArg;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((getline(&line, &len, file)) != -1)
	{
		line_number++;

		opcode = strtok(line, DELIMS);
		data = strtok(NULL, DELIMS);
		extraArg = strtok(NULL, DELIMS);

		if (extraArg)
		{
			freeAndClose(&stack, file, line);
			fprintf(stderr, "L%lu: too many arguments for %s\n", line_number, opcode);
			return (EXIT_FAILURE);
		}

		if (opcode && opcode[0] != '#')
		{
			found = 0;
			for (i = 0; instructions[i].opcode; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_number);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				freeAndClose(&stack, file, line);
				fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, opcode);
				return (EXIT_FAILURE);
			}
		}
	}

	freeAndClose(&stack, file, line);

	return (EXIT_SUCCESS);
}
