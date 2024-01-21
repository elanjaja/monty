#include "monty.h"

/**
 * pall - Print all values on the stack
 * @stack: Pointer to the stack structure
 * @line_count: Line count in the file where the instruction appears
 */
void pall(stack_t **stack, unsigned int line_count)
{
	stack_t *current_node;
	(void) stack;
	(void) line_count;

	current_node = file_data->head;

	if (current_node == NULL)
		return;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
