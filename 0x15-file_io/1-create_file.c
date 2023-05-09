#include "main.h"
#include <stdio.h>
#include <stddef.h>
/**
 * create_file - func that creates a file
 * @filename: file
 * @text_content: context to write in the file
 * Return: 1 on success, else -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, sym, cnt = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fd == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		while (text_content[cnt])
			cnt++;
		sym = write(fd, text_content, cnt);
		if (sym != cnt)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
