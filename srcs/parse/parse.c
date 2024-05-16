/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:48:28 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/16 22:01:34 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parse.h"

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

char	*rid_white_space(char *str)
{
	while (*str && (*str == '\n' || *str == ' ' || *str == '\t'))
		++str;
	return (str);
}

char	*comment(char *str)
{
	while (*str && *str != '\n')
		++str;
	if (*str)
		++str;
	while (*str && check_symbol(*str, "\t \n"))
		++str;
	return (str);
}

t_input	*parse(t_rt_dat *rt, char *filename, int *table)
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
	buf[size - 1] = 0;
	fd = open(filename, O_RDONLY);
	read(fd, buf, size);
	pt = rid_white_space(buf);
	while (pt)
		pt = is_identifier(rt, pt, table, input);
	if ((*table & 0b111) != 0b111)
		parse_error();
	close(fd);
	free(buf);
	return (input);
}
