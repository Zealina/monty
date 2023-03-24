#include "monty.h"

/**
 * engine - Where the magic happens
 * @line_number: line number
 * @stack: The stack
 * @token: token from line in getline in main
 *
 * Return: 1 if instruction is found, 0 otherwise
 */
int engine(stack_t **stack, char *token, unsigned int line_number)
{
	unsigned long int i, found_instruction;
	instruction_t instruction[] = {
		{"push", &push}, {"pall", &pall}, {"pint", &pint}, {"pop", &pop},
		{"add", &add}, {"sub", &sub}, {"mul", &mul}, {"div", &divide},
		{"mod", &mod}, {"nop", &nop},
		{"rotr", &rotr}, {"rotl", &rotl}, {"pstr", &pstr}, {"pchar", &pchar},
		{"swap", &swap}
	};

	for (i = 0; (i < sizeof(instruction) / sizeof(instruction_t)); i++)
	{
		found_instruction = 0;
		if (strcmp(token, instruction[i].opcode) == 0)
		{
			found_instruction = 1;
			instruction[i].f(stack, line_number);
			break;
		}
		else if (token[0] == '#')
			found_instruction = 1;
	}
	return (found_instruction);
}
