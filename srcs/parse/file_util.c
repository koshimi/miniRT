/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:57:34 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/11 03:00:30 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_filename(char *filename)
{
	char	*buf;
	int		idx;

	buf = filename;
	while (*buf)
	{
		if (*buf == '.')
			idx = buf - filename;
		++buf;
	}
	if (ft_strncmp(filename + idx, ".rt\0", 4))
	{
		ft_putendl_fd("enter .rt file", 1);
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	return (open(filename, O_RDONLY));
}

int	get_filesize(char *filename)
{
	const int	fd = check_filename(filename);
	int			i;
	int			temp;
	char		c[1024];

	i = 0;
	if (fd < 0)
	{
		ft_putendl_fd("can't open the file", 1);
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	while (1)
	{
		temp = read(fd, c, 1024);
		if (temp != 1024)
		{
			i += temp;
			break ;
		}
		i += temp;
	}
	close(fd);
	return (i);
}
