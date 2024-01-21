#include "monty.h"

/**
 * handle_comment - When the first non-space character of a line is #,
 * treat this line as a comment
 *
 * Return: void
 */

void handle_comment(void)
{
	/* Set opcode to "nop" for a no-operation instruction */
	file_data->opcode_instruction->opcode = "nop";

	/* Set the function pointer to the no-operation function */
	file_data->opcode_instruction->f = nop;
}
