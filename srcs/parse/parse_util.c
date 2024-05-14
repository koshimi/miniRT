/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:53:05 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/14 11:38:47 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parse.h"

void	clip_double(double min, double max, double *result)
{
	if (*result < min)
		*result = min;
	else if (*result > max)
		*result = max;
}

void	clip_int(int min, int max, int *color)
{
	if (*color < min)
		*color = min;
	else if (*color > max)
		*color = max;
}

char	*is_identifier(char *str, int *table, t_input *input)
{
	char	id[3];

	id[0] = 'a';
	id[1] = 'b';
	id[2] = 0;
	get_identifier(id, str);
	if (ft_strncmp("A", id, 2) == 0)
		return (parse_amb(str, table, input));
	if (ft_strncmp("C", id, 2) == 0)
		return (parse_camera(str, table, input));
	if (ft_strncmp("L", id, 2) == 0)
		return (parse_light(str, table, input));
	if (ft_strncmp("pl", id, 3) == 0)
		return (parse_plane(str, table, input));
	if (ft_strncmp("sp", id, 3) == 0)
		return (parse_sphere(str, table, input));
	if (ft_strncmp("cy", id, 3) == 0)
		return (parse_cylinder(str, table, input));
	if (*str)
		parse_error();
	return (NULL);
}

void	next_info(char **str)
{
	while (**str && (**str == ' ' || **str == '\t'))
		++*str;
}

void	get_identifier(char *ret, char *str)
{
	while (*str && *str != ' ' && *str != '\t' && *ret)
	{
		*ret = *str;
		++ret;
		++str;
	}
	*ret = 0;
}
