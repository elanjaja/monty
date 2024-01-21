#include "monty.h"

/**
 * opcode_function - it handles the opcode function been passed
 *
 * description: checks if the opcode string is valid
 */

void opcode_function(void)
{
	size_t i;

	static instruction_t opcodes[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", addition},
		{"sub", subtract},
		{"div", divide},
		{"mul", multiply},
		{"swap", swap},
		{"nop", nop},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (file_data->num_tokens == 0)
		return;
	if (file_data->tokens[0][0] == '#')
	{
		handle_comment();
		return;
	}
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, file_data->tokens[0]) == 0)
		{
			file_data->opcode_instruction->opcode = opcodes[i].opcode;
			file_data->opcode_instruction->f = opcodes[i].f;
			return;
		}
	}
	invalid_instruction();
}

/**
 * invalid_instruction - handles the error message for an unknown instruction.
 *
 * description: Frees resources allocated for invalid functions.
 */

void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			file_data->line_count, file_data->tokens[0]);
	close_file();
	free_tokens();
	free_file_data();
	exit(EXIT_FAILURE);
}

/**
 * close_file - closes the file
 */

void close_file(void)
{
	if (file_data->file != NULL)
	{
		fclose(file_data->file);
	}
	file_data->file = NULL;
}

/**
 * free_tokens - frees all tokenized string
 */

void free_tokens(void)
{
	int i = 0;

	if (file_data->tokens == NULL)
		return;
	while (file_data->tokens[i])
	{
		free(file_data->tokens[i]);
		i++;
	}
	free(file_data->tokens);
	file_data->tokens = NULL;
}

/**
 * free_file_data - free the file_data, the pointer to the struct
 */

void free_file_data(void)
{
	if (file_data == NULL)
		return;
	if (file_data->opcode_instruction)
	{
		free(file_data->opcode_instruction);
		file_data->opcode_instruction = NULL;
	}
	free_head();
	if (file_data->line)
	{
		free(file_data->line);
		file_data->line = NULL;
	}
	free(file_data);
}
