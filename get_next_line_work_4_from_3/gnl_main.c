#include "get_next_line.h"

// int main(void)
// {
// 	printf("Hello World!\n");
// 	return (0);
// }

void	print_lines(int fd)
{
	char	*next = NULL;
	int		i = 10;
	int 	j = 0;

	while (j < i)
	{
		next = get_next_line(fd);
		if (next != NULL)
		{
			printf("%s\n", next);
			free(next);
			next = NULL;
		}
		j++;
		// next = get_next_line(fd);
	}
	if (next != NULL)
	{
		free(next);
		next = NULL;
	}
}

int main(void)
{
	int fd1 = 0;
	// int fd2 = 0;
	// int fd3 = 0;
	// int fd4 = 0;

	printf("fd1\n");
	fd1 = open("empty.txt", O_RDONLY);
	if (fd1 == -1)
	{
		printf("fd1: fault");
		return (1);
	}
	print_lines(fd1);
	close(fd1);

	// printf("fd2\n");
	// fd2 = open("short.txt", O_RDONLY);
	// if (fd2 == -1)
	// {
	// 	printf("fd2: fault");
	// 	return (1);
	// }
	// print_lines(fd2);
	// close(fd2);
	
	// printf("fd3\n");
	// fd3 = open("one.txt", O_RDONLY);
	// if (fd3 == -1)
	// {
	// 	printf("fd3: fault");
	// 	return (1);
	// }
	// print_lines(fd3);
	// close(fd3);
	
	// printf("fd4\n");
	// fd4 = open("long.txt", O_RDONLY);
	// if (fd4 == -1)
	// {
	// 	printf("fd4: fault");
	// 	return (1);
	// }
	// print_lines(fd4);
	// close(fd4);
	// return (0);
}
