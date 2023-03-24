#include "monty.h"

/**
 * rotr - rotate the stack so that bottom becomes top
 * @stack: The stack
 * @line_number: line number
 *
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp, *trav;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		trav = (*stack);

		while (trav->next != NULL)
			trav = trav->next;
		temp = trav;
		trav = trav->prev;
		trav->next = NULL;
		temp->prev = NULL;
		temp->next = (*stack);
		(*stack)->prev = temp;
	}
}
