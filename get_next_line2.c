/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grwest <grwest@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 22:39:33 by grwest            #+#    #+#             */
/*   Updated: 2020/03/11 00:43:45 by grwest           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		has_newline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

void	ft_test(char **line, char **buff, char **storage)
{
	char	*temp;

	temp = ft_strnew(BUFF_SIZE);
	ft_memccpy(*line, *buff, '\n', BUFF_SIZE);
	*storage = ft_strchr(*buff, '\n');
	*storage = *storage + 1;
	temp = *line;
	temp[ft_strlen(*line) - 1] = '\0';
}

int		get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*storage;
	int			bytes_read;
	int			i;

	i = 0;
	*line = ft_strnew(BUFF_SIZE);
	buff = ft_strnew(BUFF_SIZE);
	storage = ft_strnew(BUFF_SIZE);
	if (has_newline(storage))
	{
		ft_test(&*line, &storage, &storage);
	}
	bytes_read = read(fd, buff, BUFF_SIZE);
	if (has_newline(buff))
		ft_test(&*line, &buff, &storage);
	printf(COLOR_GREEN "BUFF: %s\n", buff);
	printf(COLOR_YELLOW "*LINE: %s\n", *line);
	printf(COLOR_BLUE "STORAGE: %s\n", storage);
	return (0);
}

#ifdef TEST

int main(void)
{
	char *s;
	int fd;
	int i;

	i = 1;
	fd = open("test_short.txt", O_RDONLY);
	i = get_next_line(fd, &s);
	i = get_next_line(fd, &s);
	// while (i != -1)
	// {
	// 	i = get_next_line(fd, &s);
	// 	printf("%s\n", s);
	// 	if (i == 1)
	// 		printf(COLOR_GREEN "A line has been read.\n");
	// 	if (i == 0)
	// 		printf(COLOR_BLUE "Reading has finished.\n");
	// 	if (i == -1)
	// 		printf(COLOR_RED "Error\n");
	// 	printf(COLOR_NONE);
	// }
	return (0);
}

#endif
