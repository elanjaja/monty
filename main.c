#include "monty.h"

File_content *file_data = NULL;

/**
 * count_arguments - counts the number of CLI arguments passed
 * @argc: check if the arguments is == 2
 */

void count_arguments(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_file_opening - checks if the file can open and reads it
 * @file_name: name of file to be opened
 * @file: a FILE pointer
 */

void handle_file_opening(const char *file_name, FILE **file)
{
	*file = fopen(file_name, "r");
	if (*file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}

/**
 * allocated_file_content - it allocates memory to the file_contect struct
 * Return: a pointer to the address of the memory created
 */

File_content *allocated_file_content(void)
{
	file_data = (File_content *)malloc(sizeof(File_content));
	if (file_data == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file_data->file = NULL;
	file_data->line = NULL;
	file_data->line_count = 0;
	file_data->num_tokens = 0;
	file_data->tokens = NULL;
	file_data->head = NULL;
	file_data->opcode_instruction = (instruction_t *)
		malloc(sizeof(instruction_t));
	if (file_data->opcode_instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file_data->opcode_instruction->opcode = NULL;
	file_data->opcode_instruction->f = NULL;
	/* Initalize other properties of the struct here*/

	return (file_data);
}

/**
 * main - entry point of the monty interpreter
 * @argc: the argument count
 * @argv: argument vector
 * Return: 0 on sucess
 */

int main(int argc, char **argv)
{
	size_t line_size = 0;

	count_arguments(argc);
	file_data = allocated_file_content();
	handle_file_opening(argv[1], &(file_data->file));
	if (file_data->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_file_data();
		exit(EXIT_FAILURE);
	}

	while (getline(&file_data->line, &line_size, file_data->file) != -1)
	{
		file_data->line_count = file_data->line_count + 1;
		tokenize_line();
		opcode_function();
		execute_opcode();
		free_tokens();
	}

	close_file();
	free_file_data();
	return (0);
}
