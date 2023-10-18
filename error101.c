#include "monty.h"

/**
 * eror - Prints error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => no file or extra files
 * (2) => file cant be opened
 * (3) => invalid instructions in file
 * (4) => program unable to malloc more memory.
 * (5) => "push" is not an int.
 * (6) => stack empty for pint.
 * (7) => stack empty for pop.
 * (8) => stack too short for operation.
 */

void eror(int error_code, ...)
{
	va_list ag;
	char *instruction;
	int line_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			line_num = va_arg(ag, int);
			instruction = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instruction);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	stack_free();
	exit(EXIT_FAILURE);
}
