#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @stack: a pointer to the stack struct
 * @line_count: the line number of each line in the file
 */

void nop(stack_t **stack, unsigned int line_count)
{
	(void) *stack;
	(void) line_count;
}
