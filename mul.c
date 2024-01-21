#include "monty.h"

/**
 * multiply - multiplies the second top element stack
 * with the top element of the stack
 * @stack: pointer to the stack
 * @line_count: line count of file to execute
 *
 * Return: void
 */
void multiply(stack_t **stack, unsigned int line_count)
{
	int value1, value2;
	stack_t *temp;
	(void) *stack;

	temp = file_data->head;

	/*Check if the stack is too short to perform multiplication */
	if (temp == NULL || count_stack(file_data->head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	value1 = temp->n;
	temp = temp->next;
	value2 = temp->n;
	temp->n = value2 * value1;

	free(file_data->head);
	temp->prev = NULL;
	file_data->head = temp;
}
