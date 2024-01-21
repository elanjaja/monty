#include "monty.h"

/**
 * subtract - Subtracts the second top element of the stack
 *                    from the top element of the stack.
 *
 * @stack: a pointer to the stack
 * @line_count: The line count in the file where the operation is executed.
 *
 * Return: void
 */
void subtract(stack_t **stack, unsigned int line_count)
{
	int value1, value2;
	stack_t *temp;
	(void) *stack;

	temp = file_data->head;
	if (temp == NULL || count_stack(file_data->head) < 2)
	{
		fprintf(stderr, "L%d: can't subtract, stack too short\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	value1 = temp->n;
	temp = temp->next;
	value2 = temp->n;
	temp->n = value2 - value1;

	free(file_data->head);
	temp->prev = NULL;
	file_data->head = temp;
}
