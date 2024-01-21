#include "monty.h"

/**
 * count_stack - counts number of elements on the stack
 * @stack: pointer to the stack
 *
 * Return: number of elements in the stack
 */

int count_stack(stack_t *stack)
{
	stack_t *current = stack;
	int i;

	if (current == NULL)
		return (0);
	i = 1;
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

/**
 * addition - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_count: line count of file to execute
 *
 * Return: void
 */
void addition(stack_t **stack, unsigned int line_count)
{
	int value1, value2;
	stack_t *temp;
	(void) *stack;

	temp = file_data->head;
	if (temp == NULL || count_stack(file_data->head) < 2)
	{
		fprintf(stderr, "L%d: cannot add, stack too short\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	value1 = temp->n;
	temp = temp->next;
	value2 = temp->n;
	temp->n = value1 + value2;

	free(file_data->head);
	temp->prev = NULL;
	file_data->head = temp;
}
