#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_count: Line count in the file where the operation is called.
 *
 * Description:
 * If the stack is empty, it prints an error message and exits.
 * If the value at the top of the stack is a valid ASCII character,
 * it prints the character. Otherwise, it prints an error message and exits.
 */
void pchar(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	(void) *stack;

	temp = file_data->head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	if ((temp->n >= 'A' && temp->n <= 'Z') || (temp->n >= 'a' && temp->n <= 'z'))
		printf("%c\n", temp->n);
	else
	{
		/* Print an error message and exit if the value is out of range */
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_count);
		free_file_data();
		exit(EXIT_FAILURE);
	}
}
