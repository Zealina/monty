#include "monty.h"

/**
 * main - Interpreter for monty language
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	unsigned int line_number;
	FILE* fp;
	char *line;
	int found_instruction = 0, i;
	intruction_t instruction;

	intruction = {{"push", &push}, {"pall", &pall}};

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while(getline(&line, 0, fp) != -1)
	{
		line_number++;
		token = strtok(line, " \t\n");
		if (token != NULL)
		{
			for (i = 0; i < (sizeof(instruction) / sizeof(instruction_t; i++)))
			{
				if (strcmp(token, instruction[i].opcode) == 0)
				{
					found_instruction = 1;
					instruction[i].f(&stack, line_number);
					break;
				}
				if (found_instruction = 0)
				{
					dprintf(2, "L%d: unknown instruction %s", line_number, token);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	free(line);
	fclose(fp);
	return (0);
}
