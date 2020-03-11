/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grwest <grwest@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:15:09 by grwest            #+#    #+#             */
/*   Updated: 2020/03/11 03:57:15 by grwest           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char	*storage;
	char		*buff;
	char		*temp;
	int			j;

	j = 0;
	*line = ft_strnew(BUFF_SIZE);
	buff = ft_strnew(BUFF_SIZE);
	temp = ft_strnew(BUFF_SIZE);
	if (!storage)
		storage = ft_strnew(BUFF_SIZE);
	if (read(fd, buff, BUFF_SIZE) > 0)
		storage = ft_strjoin(storage, buff);
	if (*storage == '\n')
		storage++;
	while (*storage && *storage != '\n')
		temp[j++] = *storage++;
	printf(COLOR_GREEN "BUFF: %s\n", buff);
	printf(COLOR_YELLOW "*LINE: %s\n", temp);
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
	i = get_next_line(fd, &s);
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
