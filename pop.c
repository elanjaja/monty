#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: a pointer to the stack struct
 * @line_count: the line count of each line in the file
 */

void pop(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;
	(void) *stack;

	temp = file_data->head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop from an empty stack\n", line_count);
		close_file();
		free_tokens();
		free_file_data();
		exit(EXIT_FAILURE);
	}
	file_data->head = temp->next;
	if (file_data->head != NULL)
	{
		file_data->head->prev = NULL;
	}
	free(temp);
}
