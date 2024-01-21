#include "monty.h"

/**
 * rotl - Rotates the stack to the top, moving the first
 * element to the end while keeping the rest intact.
 *
 * @stack: Pointer to the stack.
 * @line_count: Line count in the file being executed.
 *
 * Return: Void
 */
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp, *current;
	(void) *stack;
	(void) line_count;

	/* Check if there are at least two elements in the stack */
	if (count_stack(file_data->head) < 2)
	{
		return; /* Not enough elements to rotate */
	}

	tmp = file_data->head;
	current = tmp->next;
	file_data->head = current;
	/* Traverse the stack to find the last element */
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			/* Rotate the stack by updating pointers */
			current->next = tmp;
			tmp->next = NULL;
			tmp->prev = current;
			break;
		}
		current = current->next;
	}
}
