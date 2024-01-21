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
	(void) *stack;
	(void) line_count;

	temp = file_data->head;
	count = 0;
	if (temp == NULL)
	{
		printf("\n");
	}
	else
	{
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
