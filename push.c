#include "monty.h"

/**
 * push - push an element to the stack
 * 
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *head;

	head = (*list);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	new->n = arg;
	new->prev = NULL;
	if (head == NULL)
	{
		new->next = NULL;
		head = new;
		return (head);
	}
	new->next = head;
	head->prev = new;
	head = new;
	return (head);
}
