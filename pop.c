#include "monty.h"

/**
 * pop - Remove the top elementin stack
 * @stack: The stack
 * @line_number: Whatever
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		dprintf(2, "L%d: Can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	};
	*stack = (*stack)->next;
	free(temp);
}
