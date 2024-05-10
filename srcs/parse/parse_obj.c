/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:05:31 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/11 05:45:32 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*parse_cylinder(char *str, int *table, t_input *input)
{
	if (*table & 1 << OTYPE_CYLINDER)
		parse_error();
	*table |= 1 << OTYPE_CYLINDER;
	next_info(&str);
	str += 2;
	next_info(&str);
	check_misconfig(str);
	parse_coordinate(&str, &input->cyl.position);
	parse_forward(&str, &input->cyl.forward);
	input->cyl.diameter = ft_atod(&str, " \t");
	next_info(&str);
	input->cyl.height = ft_atod(&str, " \t");
	next_info(&str);
	parse_color(&str, &input->cyl.color);
	return (str);
}

char	*parse_plane(char *str, int *table, t_input *input)
{
	if (*table & 1 << OTYPE_PLANE)
		parse_error();
	*table |= 1 << OTYPE_PLANE;
	next_info(&str);
	str += 2;
	next_info(&str);
	check_misconfig(str);
	parse_coordinate(&str, &input->pl.position);
	parse_forward(&str, &input->pl.forward);
	parse_color(&str, &input->pl.color);
	return (str);
}
