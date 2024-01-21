#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: a pointer to the stack struct
 * @line_count: the line count in the Monty script
 */

void pint(stack_t **stack, unsigned int line_count)
{
	stack_t *current;
	(void) *stack;

	current = file_data->head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		close_file();
		free_tokens();
		free_file_data();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
