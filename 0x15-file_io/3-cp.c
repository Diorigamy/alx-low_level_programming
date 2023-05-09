#include "main.h"
/**
 * main - func that copies the content of a file to another file
 * @argc:  number of arguments
 * @argv: an array of arguments
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	int fdrd, fdwr, tak, nw, str;
	char BUFF[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fdrd = open(argv[1], O_RDONLY);
	if (fdrd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fdwr = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((str = read(fdrd, BUFF, BUFSIZ)) > 0)
	{
		if (fdwr < 0 || write(fdwr, BUFF, str) != str)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fdrd);
			exit(99);
		}
	}
	if (str == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	tak = close(fdrd);
	nw = close(fdwr);
	if (tak == -1 ||  nw == -1)
	{
		if (tak == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdrd);
		if (nw == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdwr);
		exit(100);
	}
	return (0);
}
