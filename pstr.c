#include "monty.h"

/**
 * pstr - Print the string in stack
 * @stack: The Stack
 * @line_number: Line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		if (temp->n < 0 || temp->n > 127)
		{
			dprintf(2, "L%d: can't pstr, value out of range\n", line_number);
			temp = NULL;
			exit(EXIT_FAILURE);
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
