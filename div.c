#include "monty.h"

/**
 * div - Divide second element by first
 * @stack: The stack
 * @line_number: The line_number
 *
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *first_item, *second_item;
	int i = 0;

	first_item = *stack;
	while (first_item != NULL)
	{
		i++;
		first_item = first_item->next;
	}
	if (*stack == NULL || i < 2)
	{
		dprintf(2, "L%d: Can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_item = *stack;
	second_item = (*stack)->next;
	if (first_item->n == 0)
	{
		dprintf(2, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	(second_item->n) /= (first_item->n);
	*stack = second_item;
	(*stack)->prev = NULL;
	free(first_item);
}
