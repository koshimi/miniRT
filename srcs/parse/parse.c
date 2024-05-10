/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:48:28 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/11 03:19:10 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../headers/minirt.h"
#include "parse.h"

void	init_variable(double *sign, double *ret, int *decimal, char **str)
{
	*sign = 1.0;
	*ret = 0;
	*decimal = 0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
		{
			*sign = -*sign;
			++*str;
		}
	}
}

t_input	*parse(char *filename)
{
	int		size;
	int		fd;
	char	*buf;
	char	*pt;
	t_input	*input;

	size = get_filesize(filename);
	buf = malloc(size);
	input = malloc(sizeof(t_input));
	if (!buf || !input)
		exit(1);
	pt = buf;
	fd = open(filename, O_RDONLY);
	read(fd, buf, size);
	size = 0;
	while (pt)
		pt = is_identifier(pt, &size, input);
	if ((size & 0b111) != 0b111)
		parse_error();
	close(fd);
	free(buf);
	return (input);
}
