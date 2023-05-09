#include "main.h"
#include <stdio.h>
/**
 * read_textfile - func that reads text & prints to display
 * @filename: file to read from
 * @letters: number of letters to read & display
 * Return: Actual no of letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int use, sym, fd;
	char *ptr;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}

	ptr = malloc(sizeof(char) * letters);

	if (ptr == NULL)
	{
		return (0);
	}
	use = read(fd, ptr, letters);
	if (use == -1)
	{
		free(ptr);
		return (0);
	}
	ptr[use] = '\0';
	close(fd);
	sym = write(STDOUT_FILENO, ptr, use);
	if (sym == -1)
	{
		free(ptr);
		return (0);
	}
	free(ptr);
	return (sym);
}
