#include "main.h"
/**
 * main - a func that copies the content of a file to another file
 * @argc: the count of arguments
 * @argv: an array of arguments(args vector)
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	int fd_rd, fd_wr, rit, str, drp;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy file_from file_to\n");
		exit(97);
	}
	fd_rd = open(argv[1], O_RDONLY);
	if (fd_rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		exit(98);
	}
	fd_wr = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((drp = read(fd_rd, buff)) > 0)
	{
		if (fd_wr < 0 || write(fd_wr, buff, drp) != drp)
		{
			dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", argv[2]);
			close(fd_rd);
			exit(99);
		}
	}
	if (drp == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		exit(98);
	}
	rit = close(fd_rd);
	str = close(fd_wr);
	if (rit == -1 ||  str == -1)
	{
		if (rit == -1)
			dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", fd_rd);
		if (str == -1)
			dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", fd_wr);
		exit(100);
	}
	return (0);
}
