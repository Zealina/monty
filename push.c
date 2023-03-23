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
	int data, i;

	head = (*stack);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	push_line = strtok(NULL, " ");
	if (push_line == NULL)
	{
		dprintf(2, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; push_line[i]; i++)
	{
		if (isdigit(push_line[i]) == 0 && push_line[i] != '-')
		{
			dprintf(2, "L%d: usage: push integer", line_number);
			exit(EXIT_FAILURE);
		}
	}
	data = atoi(push_line);
	new->n = data;
	new->prev = NULL;
	new->next = head;
	if (head != NULL)
		head->prev = new;
	head = new;
}
