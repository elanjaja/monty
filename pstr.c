#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_count: line count of file to execute
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	int count;

	/* Suppress unused parameter warnings */
	(void) *stack;
	(void) line_count;

	/* Set the current node to the head of the stack */
	temp = file_data->head;
	count = 0;

	/* Check if the stack is empty */
	if (temp == NULL)
	{
		printf("\n");
	}
	else
	{
		/* Iterate through the stack */
		while (temp != NULL)
		{
			if (!(temp->n >= 65 && temp->n <= 90)
					&& !(temp->n >= 97 && temp->n <= 122))
			{
				if (count == 0)
					break;
				printf("\n");
				break;
			}
			else
			{
				printf("%c", temp->n);

				if (temp->next == NULL)
					printf("\n");
			}
			temp = temp->next;
			count++;
}
}
}
