/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_non_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:04:03 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/14 21:27:29 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parse.h"

char	*parse_light(t_rt_dat *rt, char *str, int *table, t_input *input)
{
	void	*item;

	if (*table & 1 << OTYPE_LIGHT && (*table & BONUS_FLAG) != BONUS_FLAG)
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
	item = (void *)new_light(&input->lit);
	if (item == NULL)
		exit(1);
	add_lst(rt->lit_list, new_node(item, OTYPE_LIGHT));
	return (str);
}

char	*parse_camera(t_rt_dat *rt, char *str, int *table, t_input *input)
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
	rt->cam = new_camera(&input->cam);
	return (str);
}

char	*parse_amb(t_rt_dat *rt, char *str, int *table, t_input *input)
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
	rt->amb = new_ambient(&input->amb);
	return (str);
}
