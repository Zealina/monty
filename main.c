#include "monty.h"

/**
 * main - Interpreter for monty language
 * @argc: the count of arguments
 * @argv: Pointer to the arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	FILE *fp = fopen(argv[1], "r");
	char *line;
	long unsigned int i, found_instruction = 0, line_size = 0;
	stack_t *stack = NULL;
	char *token;
	instruction_t instruction[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap}
	};

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &line_size, fp) != -1)
	{
		line_number++;
		token = strtok(line, " \n\t");
		if (token != NULL)
		{
			for (i = 0; i < (sizeof(instruction) / sizeof(instruction_t)); i++)
			{
				found_instruction = 0;
				if (strcmp(token, (instruction[i]).opcode) == 0)
				{
					found_instruction = 1;
					(instruction[i]).f(&stack, line_number);
					break;
				}
			}
			if (!found_instruction)
			{
				dprintf(2, "L%d: unknown instruction %s\n", line_number, token);
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(fp);
	return (0);
}
