#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

# define BUFFER_SIZE 64

char	*get_next_line(int fd);
size_t	buffering(char *buffer, char *dest, int fd);
char	*extract_line(char *source, char *leftover, size_t size);
size_t	newline_checker(char *search, size_t size);
char	*save_string_alloc(char *src, char *dest, size_t size);
char	*save_string_realloc(char *src, char *dest, size_t size);
size_t	freeing_strcpy(char *dest, char *source);
size_t	reallocate(char *dest, size_t size);

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	char *ptr;

	fd = open("testing.txt", O_RDONLY);
	 if (fd == -1)
	 {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully\n");
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	close(fd);
	return (0);
}


char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	char		buffer[BUFFER_SIZE]; // eventually in buffering function
	char		*storage;
	char		*line;
	size_t		size;

	storage = malloc(0);
	size = buffering(buffer, storage, fd);
	if (!size)
		return (NULL);
	line = extract_line(storage, leftover[fd], size);
	return (line);
}

size_t	buffering(char *buffer, char *dest, int fd)
{
	int		READ_STATUS;
	size_t	size;
	size_t	newline;

	size = 0;
	newline = 0;
	while (!newline && ((READ_STATUS = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		size += READ_STATUS;
		newline = newline_checker(buffer, size);
		if (size == (size_t)READ_STATUS)
		{
			if (!save_string_alloc(buffer, dest, size))
				return(0);
		}
		else
		{
			if (!save_string_realloc(buffer, dest, size))
				return(0);
		}
	}
	if (READ_STATUS == -1)
		return (0);
	return (size);
}

char	*extract_line(char *source, char *leftover, size_t size)
{
	char	*line;
	size_t	newline_pos;

	line = NULL;
	if (!(newline_pos = newline_checker(source, size)))
	{
		leftover = 0;
		return (source);
	}
	save_string_alloc(source, line, newline_pos);
	save_string_alloc(&source[newline_pos], leftover, size - newline_pos); // need to free leftofver.
	return (line);
}

size_t	newline_checker(char *search, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		if (search[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*save_string_alloc(char *src, char *dest, size_t size)
{
	size_t	i;

	i = 0;
	if (!(dest = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < size)
	{
			dest[i] = src[i];
			i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*save_string_realloc(char *src, char *dest, size_t size)
{
	size_t	i;
	size_t	prev_size;

	i = 0;
	if (!(prev_size = reallocate(dest, size)))
		return (NULL);
	while (prev_size < size)
		dest[prev_size++] = src[i++];
	dest[size] = '\0';
	return (dest);
}

size_t	reallocate(char *dest, size_t size)
{
	char 	*backup;
	
	if (!(backup = malloc(size * sizeof(char))))
	{
		free(dest);
		return (0);
	}
	freeing_strcpy(backup, dest);
	if (!(dest = malloc((size + 1) * sizeof(char))))
	{
		free(backup);
		return(0);
	}
	return (freeing_strcpy(dest, backup));
}

size_t	freeing_strcpy(char *dest, char *source)
{
	size_t i;

	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	free(source);
	return (i);
}
