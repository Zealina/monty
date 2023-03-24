#include "monty.h"

/**
 * rotl - rotate the stack so that top becomes bottom
 * @stack: The stack
 * @line_number: line number
 *
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp, *trav;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack);
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		trav = (*stack);

		while (trav->next != NULL)
			trav = trav->next;
		trav->next = temp;
		temp->prev = trav;
		temp->next = NULL;
	}
}
