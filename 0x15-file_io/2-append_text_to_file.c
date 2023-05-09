#include "main.h"
#include <stddef.h>
/**
 * append_text_to_file - a func that appends text to a file
 * @filename: file
 * @text_content: content to append
 * Return: 1 successs else 0
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int use, cnt = 0, fd;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		while (text_content[cnt])
			cnt++;
		use = write(fd, text_content, cnt);
		if (use != cnt)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
