/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:05:31 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/14 20:11:34 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parse.h"

char	*parse_cylinder(t_rt_dat *rt, char *str, int *table, t_input *input)
{
	void	*item;

	(void) table;
	next_info(&str);
	str += 2;
	next_info(&str);
	check_misconfig(str);
	parse_coordinate(&str, &input->cyl.position);
	parse_forward(&str, &input->cyl.forward);
	input->cyl.diameter = ft_atod(&str, " \t");
	if (input->cyl.diameter <= 0)
		parse_error();
	next_info(&str);
	input->cyl.height = ft_atod(&str, " \t");
	if (input->cyl.height <= 0)
		parse_error();
	next_info(&str);
	parse_color(&str, &input->cyl.color);
	item = (void *)new_cylinder(&input->cyl);
	if (item == NULL)
		exit(1);
	add_lst(rt->obj_list, new_node(item, OTYPE_CYLINDER));
	return (str);
}

char	*parse_sphere(t_rt_dat *rt, char *str, int *table, t_input *input)
{
	void	*item;

	(void) table;
	next_info(&str);
	str += 2;
	next_info(&str);
	check_misconfig(str);
	parse_coordinate(&str, &input->sph.position);
	input->sph.diameter = ft_atod(&str, " \t");
	if (input->sph.diameter <= 0)
		parse_error();
	next_info(&str);
	parse_color(&str, &input->sph.color);
	item = (void *)new_sphere(&input->sph);
	if (item == NULL)
		exit(1);
	add_lst(rt->obj_list, new_node(item, OTYPE_SPHERE));
	return (str);
}

char	*parse_plane(t_rt_dat *rt, char *str, int *table, t_input *input)
{
	void	*item;

	(void) table;
	next_info(&str);
	str += 2;
	next_info(&str);
	check_misconfig(str);
	parse_coordinate(&str, &input->pl.position);
	parse_forward(&str, &input->pl.forward);
	parse_color(&str, &input->pl.color);
	item = (void *)new_plane(&input->pl);
	if (item == NULL)
		exit(1);
	add_lst(rt->obj_list, new_node(item, OTYPE_PLANE));
	return (str);
}
