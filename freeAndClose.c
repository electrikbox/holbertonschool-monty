#include "monty.h"

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
