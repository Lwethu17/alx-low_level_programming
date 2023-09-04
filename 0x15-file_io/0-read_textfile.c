#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints standard output
 * @filename: Name of the file
 * @letters: the number of letters the function should read and print
 * Return: the actual number of letters printed, if fails 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *size;
	ssize_t a;
	ssize_t b;
	ssize_t c;

	a = open(filename, O_RDONLY);
	if (a == -1)
		return (0);
	size = malloc(sizeof(char) * letters);
	c = read(a, size, letters);
	b = write(STDOUT_FILENO, size, c);

	free(size);
	close(a);
	return (b);
}
