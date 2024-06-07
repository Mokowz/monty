#include "monty.h"
void (*f)(stack_t **stack, unsigned int line_number);
global_t globs;
/**
 * free_glob_vars - frees the global variables
 *
 * Return: no return
 */
void free_glob_vars(void)
{
	free_list_int(globs.head);
	free(globs.buffer);
	fclose(globs.fd);
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * start_global_vars - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_global_vars(FILE *fd)
{
	globs.lifo = 1;
	globs.cont = 1;
	globs.arg = NULL;
	globs.head = NULL;
	globs.fd = fd;
	globs.buffer = NULL;
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_global_vars(fd);
	nlines = getline(&globs.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(globs.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", globs.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glob_vars();
				exit(EXIT_FAILURE);
			}
			globs.arg = _strtoky(NULL, " \t\n");
			f(&globs.head, globs.cont);
		}
		nlines = getline(&globs.buffer, &size, fd);
		globs.cont++;
	}

	free_glob_vars();

	return (0);
}
