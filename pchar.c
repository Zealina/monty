#include "monty.h"

/**
 * pchar - Convert int to char in stack top
 * @stack: Stack top
 * @line_number: the line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n <= 0 || (*stack)->n >= 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
