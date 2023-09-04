#include "main.h"

int main(int argc, char *argv[])
{
	monty_stack_t *stack = NULL;
	size_t line_number = 0, len = 0;
	char *line = NULL, *opcode;
	ssize_t read;
	FILE *file;
	int found, i;

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

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");
		buff = strtok(NULL, " \n\t\r");

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
				freeStack(&stack);
				free(line);
				fclose(file);

				fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, opcode);
				return (EXIT_FAILURE);
			}
		}
	}

	freeStack(&stack);
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
