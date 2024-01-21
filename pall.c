#include "monty.h"

/**
 * pall - Print all values on the stack
 * @stack: Pointer to the stack structure
 * @line_count: Line count in the file where the instruction appears
 */
void pall(stack_t **stack, unsigned int line_count)
{
	stack_t *current_node;

	/* Avoid compiler warnings about unused parameters */
	(void) stack;
	(void) line_count;

	/* Set the current_node pointer to the head of the stack */
	current_node = file_data->head;

	/* If the stack is empty, return */
	if (current_node == NULL)
		return;

	/* Traverse the stack and print each element */
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
