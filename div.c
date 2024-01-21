#include "monty.h"

/**
 * divide - Divides the second element from the top of the stack
 * by the top element of the stack.
 * @stack: pointer to the stack
 * @line_count: Line count in the file where the instruction appears
 *
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_count)
{
	int value1, value2;
	stack_t *temp;
	(void) *stack;

	temp = file_data->head;
	if (temp == NULL || count_stack(file_data->head) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	value1 = temp->n;
	if (value1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	value2 = temp->n;
	temp->n = value2 / value1;

	free(file_data->head);
	temp->prev = NULL;
	file_data->head = temp;
}
