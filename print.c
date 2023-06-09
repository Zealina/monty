#include "monty.h"

/**
 * pall - Print all the elements in the stack
 * @stack: The stack
 * @line_number: Not needed
 *
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *trav;

	trav = (*stack);
	while (trav != NULL)
	{
		printf("%d\n", trav->n);
		trav = trav->next;
	}
}
/**
 * pint - Print elementat top of stack
 * @stack: The stack
 * @line_number: Not needed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d Can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * nop - Does nothing
 * @stack: the stack
 * @line_number:
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
