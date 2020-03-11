/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grwest <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:47:44 by grwest            #+#    #+#             */
/*   Updated: 2020/03/05 04:04:16 by grwest           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static int	i = 0;
	char		buff[BUFF_SIZE + 1];
	char		*file;
	static char	**split;

	if (i > 0 && split[i] == '\0')
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (i == 0)
	{
		file = ft_strnew(BUFF_SIZE);
		while ((read(fd, buff, BUFF_SIZE)) != 0)
			file = ft_strjoin(file, buff);
		file = ft_strjoin(file, "\0");
		split = ft_strsplit(file, '\n');
	}
	*line = split[i++];
	return (split[i] != '\0');
}

#ifdef TEST

int		main(void)
{
	char	*s;
	int		fd;
	int		i;

	i = 1;
	fd = open("test2.txt", O_RDONLY);
	while (i != -1)
	{
		i = get_next_line(fd, &s);
		printf("%s\n", s);
		if (i == 1)
			printf(COLOR_GREEN "A line has been read.\n");
		if (i == 0)
			printf(COLOR_BLUE "Reading has finished.\n");
		if (i == -1)
			printf(COLOR_RED "Error\n");
		printf(COLOR_NONE);
	}
	return (0);
}

#endif
