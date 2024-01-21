#include "monty.h"

/**
 * execute_opcode - Executes the opcode if a valid command is passed
 */

void execute_opcode(void)
{
	stack_t *stack = NULL;

	/* Check if a valid function pointer is available for the opcode */
	if (file_data->opcode_instruction->f)
	{
		/* Call the function associated with the opcode */
		file_data->opcode_instruction->f(&stack,
				file_data->line_count);
	}
	else
		/* Handle case when the opcode is invalid */
		invalid_instruction();
}
