#include "monty.h"

/**
 * rotr - rotates the stack to the bottom, The last
 * element of the stack becomes the top element of the stack
 *
 * @stack: pointer to the stack
 * @line_count: Line count in the file where the operation is called
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp, *current;
	(void) *stack;
	(void) line_count;

	tmp = file_data->head;
	/* If the stack has less than 2 elements, no rotation is needed */
	if (count_stack(file_data->head) < 2)
	{
		return;
	}

	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			current = tmp;
			break;
		}
		tmp = tmp->next;
	}
	current->prev->next = NULL;
	current->next = file_data->head;
	current->prev = NULL;
	file_data->head = current; /* Update the head to the last element */
}
