#include "monty.h"

/**
 * push - prints all the values on the stack
 * @stack: a pointer to the stack struct
 * @line_count: the line count of each line in the file
 */

void push(stack_t **stack, unsigned int line_count)
{
	if (file_data->num_tokens <= 1 || !(is_digit(file_data->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		close_file();
		free_tokens();
		free_file_data();
		exit(EXIT_FAILURE);
	}
	/*printf("in push DEBUG: Token[1]: %s\n", file_data->tokens[1]);*/
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close_file();
		free_tokens();
		free_file_data();
		exit(EXIT_FAILURE);
	}

	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(file_data->tokens[1]);
	if (file_data->head != NULL)
	{
		(*stack)->next = file_data->head;
		file_data->head->prev = *stack;
	}
	file_data->head = *stack;
}

/**
 * is_digit - checks if a string is a digit
 * @str: the string to check
 * Return: 0 on success
 */

int is_digit(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		if (a == 0 && str[a] == '-' && str[a + 1])
		{
			a++;
			continue;
		}
		if (str[a] < '0' || str[a] > '9')
		{
			return (0);
		}
		a++;
	}
	return (1);
}

/**
 * free_stack - frees the memory allocated for the stack
 * @head: a pointer to the head of the node
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}

/**
 * free_head - frees the head pointer of the stack
 */

void free_head(void)
{
	if (file_data->head)
		free_stack(file_data->head);
	file_data->head = NULL;
}
