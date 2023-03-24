#include "monty.h"

/**
 * push - push an element to the stack
 * @stack: The stack
 * @line_number: Line number in the bytecode
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *head;
	char *push_line;
	int i;

	head = (*stack);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	push_line = strtok(NULL, " \n");
	if (push_line == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; push_line[i]; i++)
	{
		if (isdigit(push_line[i]) == 0 && push_line[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer,\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new->n = atoi(push_line);
	new->prev = NULL;
	if (head != NULL)
		head->prev = new;
	new->next = head;
	*stack = new;
}
/**
 * swap - swap the two topmost elements in stack
 * @stack: The stack
 * @line_number: Line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *old_top, *third_item;
	int i = 0;

	old_top = (*stack);
	while (old_top != NULL)
	{
		i++;
		old_top = old_top->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: Can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	old_top = (*stack)->prev;
	(*stack)->prev = NULL;
	third_item = (*stack)->next;
	old_top->next = third_item;
	old_top->prev = (*stack);
	if (i > 2)
		third_item->prev = old_top;
	(*stack)->next = old_top;
}
