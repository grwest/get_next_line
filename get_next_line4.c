/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grwest <grwest@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:58:39 by grwest            #+#    #+#             */
/*   Updated: 2020/03/11 11:25:50 by grwest           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_old_storage(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (s + i + 1);
		i++;
	}
	return (NULL);
}

char	*copy_till_nl(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			return (dst);
		dst[i] = src[i];
		i++;
	}
	return (NULL);
}

int		storage_has_nl(char **s)
{
	int		i;

	i = 0;
	while (s[0][i++])
		if (s[0][i] == '\n')
			return (1);
	return (0);
}

int		read_to_storage(const int fd, char **storage)
{
	char	*buff;
	char	*to_kill;
	int		bytes_read;

	buff = ft_strnew(BUFF_SIZE);
	bytes_read = read(fd, buff, BUFF_SIZE);
	to_kill = *storage;
	*storage = ft_strjoin(*storage, buff);
	free(to_kill);
	return (bytes_read);
}

int		get_next_line(const int fd, char **line)
{
	static char *storage;
	char		*to_kill;
	int			i;

	i = 0;
	if (!storage)
		storage = ft_strnew(1);
	while (!(storage_has_nl(&storage)))
		read_to_storage(fd, &storage);
	*line = ft_strnew(ft_strlen(storage));
	*line = copy_till_nl(*line, storage);
	to_kill = storage;
	storage = ft_strdup(remove_old_storage(storage));
	printf(COLOR_BLUE "%s\n", storage);
	free(to_kill);
	return (!!*storage || read_to_storage(fd, &storage) > 0);
}

#ifdef TEST

int main(void)
{
	char *s;
	int fd;
	int i;

	i = 1;
	fd = open("test_long.txt", O_RDONLY);
	while (i > 0)
	{
		i = get_next_line(0, &s);
		printf(COLOR_WHITE "%s\n", s);
	}
	return (0);
}

#endif
