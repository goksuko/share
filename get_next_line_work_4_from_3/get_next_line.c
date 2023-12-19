#include "get_next_line.h"

static char	*read_to_buffer(int fd, char *buffer)
{
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free_there(&buffer));
	buffer[bytes_read] = '\0';
	return (buffer);
}

static char	*trim_leftover(char *temp)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// printf("trim: temp: %s\n", temp);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	// printf("trim: i: %d\n", i);
	while (j <= i)
	{
		new_line[j] = temp[j];
		j++;
	}
	new_line[j] = '\0';
	// printf("trim: new_line: %s$\n", new_line);
	return (new_line);
}


char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*leftover;
	char		*new_line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &new_line, 0) < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	// printf("line: %s\n", line);
	leftover = NULL;
	// printf("leftover: %s\n", leftover);
	while (fd >= 0 && BUFFER_SIZE > 0 && !leftover)
	{
		buffer = read_to_buffer(fd, buffer);
		// printf("1: buffer: %s$\n", buffer);
		if (!buffer && line[0] == '\0')
		{
			free_there(&line);
			return (NULL);
		}
		if (!buffer && line)
		{
			new_line = ft_strdup(line);
			// printf("5: line: %s\n", line);
			// printf("6: new_line: %s\n", new_line);
			free_there(&line);
			return (new_line);
		}
		leftover = ft_strchr(buffer, '\n');
		// printf("2: leftover: %s$\n", leftover);
		temp = ft_strjoin(line, buffer);
		// printf("3: line: %s$\n", line);
		// printf("3: temp: %s$\n", temp);
		free_there(&buffer);
		free_there(&line);
		line = ft_strdup(temp);
		free_there(&temp);
		if (leftover)
		{
			new_line = trim_leftover(line);
			// printf("4: line: %s$\n", line);
			// printf("4: new_line: %s$\n", new_line);
			free_there(&line);
			return (new_line);
		}
	}
	free_there(&line);
	return (NULL);
}




//copilot below


// char	*ft_get_line(char **str)
// {
// 	char	*line;
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	while ((*str)[i] && (*str)[i] != '\n')
// 		i++;
// 	if ((*str)[i] == '\0')
// 	{
// 		line = ft_strdup(*str);
// 		free(*str);
// 		*str = NULL;
// 		return (line);
// 	}
// 	line = ft_substr(*str, 0, i + 1);
// 	tmp = ft_strdup(*str + i + 1);
// 	free(*str);
// 	*str = tmp;
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*str;
// 	char		*line;
// 	int			ret;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!(line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
// 		return (NULL);
// 	if (!str)
// 		str = ft_strdup("");
// 	while (!ft_strchr(str, '\n') && (ret = read(fd, line, BUFFER_SIZE)) > 0)
// 	{
// 		line[ret] = '\0';
// 		str = ft_strjoin(str, line);
// 	}
// 	free(line);
// 	if (ret < 0)
// 		return (NULL);
// 	return (ft_get_line(&str));
// }
