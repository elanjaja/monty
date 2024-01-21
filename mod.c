#include "monty.h"

/**
 * mod - computes the remainder of the division of the
 * second top element of stack by the top element of the stack
 *
 * @stack: pointer to the stack
 * @line_count: line count of file being executed
 *
 * Return: no return
 */
void mod(stack_t **stack, unsigned int line_count)
{
	int value1, value2;
	stack_t *temp;
	(void) *stack;

	temp = file_data->head;

	/* Check if the stack is too short */
	if (temp == NULL || count_stack(file_data->head) < 2)
	{
		fprintf(stderr, "L%d: can't perform mod, stack too short\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	/* Get the top element of the stack as the value1 */
	value1 = temp->n;
	if (value1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	/* Move to the second top element in the stack */
	temp = temp->next;
	value2 = temp->n;
	temp->n = value2 % value1;

	free(file_data->head);

	/* Update the pointers to reflect the new top element */
	temp->prev = NULL;
	file_data->head = temp;
}
