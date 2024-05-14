/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_non_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:04:03 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/14 13:56:37 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parse.h"

char	*parse_light(char *str, int *table, t_input *input)
{
	if (*table & 1 << OTYPE_LIGHT)
		parse_error();
	*table |= 1 << OTYPE_LIGHT;
	next_info(&str);
	str += 1;
	next_info(&str);
	check_misconfig(str);
	parse_coordinate(&str, &input->lit.position);
	input->lit.ratio = ft_atod(&str, " \t");
	clip_double(0.0, 1.0, &input->lit.ratio);
	next_info(&str);
	parse_color(&str, &input->lit.color);
	return (str);
}

char	*parse_camera(char *str, int *table, t_input *input)
{
	if (*table & 1 << OTYPE_CAMERA)
		parse_error();
	*table |= 1 << OTYPE_CAMERA;
	next_info(&str);
	str += 1;
	next_info(&str);
	check_misconfig(str);
	parse_coordinate(&str, &input->cam.position);
	parse_forward(&str, &input->cam.forward);
	seperate_color(&str, &input->cam.fov, "\t \n");
	clip_int(0, 180, &input->cam.fov);
	while (*str && check_symbol(*str, "\t \n"))
		++str;
	return (str);
}

char	*parse_amb(char *str, int *table, t_input *input)
{
	if (*table & 1 << OTYPE_AMBIENT)
		parse_error();
	*table |= 1 << OTYPE_AMBIENT;
	next_info(&str);
	str += 1;
	next_info(&str);
	check_misconfig(str);
	input->amb.ratio = ft_atod(&str, "\t ");
	next_info(&str);
	parse_color(&str, &input->amb.color);
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
