#include "monty.h"

/**
 * tokenize_line - Tokenizes the input string.
 */

void tokenize_line(void)
{
	int i = 0;
	char *line_copy = NULL, *token = NULL;

	line_copy = malloc(sizeof(char) * (strlen(file_data->line) + 1));
	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, file_data->line);
	file_data->num_tokens = 0;
	token = strtok(line_copy, " \n\t");
	while (token)
	{
		file_data->num_tokens += 1;
		token = strtok(NULL, " \n\t");
	}
	file_data->tokens = malloc(sizeof(char *) *
			(file_data->num_tokens + 1));
	if (file_data->tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_file_data();
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, file_data->line);
	token = strtok(line_copy, " \n\t");
	while (token)
	{
		file_data->tokens[i] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (file_data->tokens[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			/* free_file_data(); */
			exit(EXIT_FAILURE);
		}
		strcpy(file_data->tokens[i], token);
		token = strtok(NULL, " \n\t");
		i++;
	}
	file_data->tokens[i] = NULL;
	free(line_copy);
}
