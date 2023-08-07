#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: The file to be read
 * @letters: the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 * if filename is NULL return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *size;
	ssize_t a;
	ssize_t b;
	ssize_t c;

	a = access(filename, O_RDONLY);
	if (a == -1)
		return (0);
	size = malloc(sizeof(char) * letters);
	c = read(a, size, letters);
	b = write(STDOUT_FILENO, size, c);

	free(size);
	close(a);
	return (b);
}
