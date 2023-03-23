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
