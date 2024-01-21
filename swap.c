#include "monty.h"

/**
 * swap - swaps the values top two elements on the stack
 * @stack: a pointer to the stack struct
 * @line_count: the line count in the file where the operation is called
 */

void swap(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;
	int temp_value;

	(void) *stack;

	/* Check if there are at least two elements on the stack */
	if (file_data->head == NULL || file_data->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't perform swap, stack too short\n", line_count);
		close_file();
		free_tokens();
		free_file_data();
		exit(EXIT_FAILURE);
	}

	temp = file_data->head;
	temp_value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_value;
}
