/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:01:25 by moson             #+#    #+#             */
/*   Updated: 2024/04/28 07:01:26 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

#include <stdio.h>

static t_hit	get_hit_by_o_type(t_ray ray, t_node *node, int idx)
{
	t_hit	res;

	if (node->o_type == OTYPE_PLANE)
		res = is_hit_plane(ray, (t_o_pl *)node->item, idx);
	else if (node->o_type == OTYPE_SPHERE)
		res = is_hit_sphere(ray, (t_o_sph *)node->item, idx);
	else if (node->o_type == OTYPE_CYLINDER)
		res = is_hit_cylinder(ray, (t_o_cyl *)node->item, idx);
	else
		res.is_hit = 0;
	return (res);
}

static t_hit	get_closer_hit(t_hit h1, t_hit h2)
{
	if (h1.is_hit == 0)
		return (h2);
	else if (h2.is_hit == 0)
		return (h1);
	else if (h1.sqrmag < h2.sqrmag)
		return (h1);
	else
		return (h2);
}

t_hit	get_first_hit(t_rt_dat *rt, t_ray ray, int skip_idx)
{
	int		idx;
	t_node	*node;
	t_hit	cur_hit;
	t_hit	res_hit;

	res_hit.is_hit = 0;
	res_hit.hit_idx = -1;
	idx = -1;
	node = rt->obj_list->head;
	while (++idx < rt->obj_list->size)
	{
		if (idx != skip_idx)
		{
			cur_hit = get_hit_by_o_type(ray, node, idx);
			res_hit = get_closer_hit(cur_hit, res_hit);
		}
		node = node->next;
	}
	return (res_hit);
}

int	has_shadow(t_rt_dat *rt, t_vector3_double lit_pos, \
				t_vector3_double hit_pos)
{
	t_hit	hit;
	int		idx;
	t_node	*node;
	t_ray	ray_to_lit;
	double	sqrmag_to_lit;

	ray_to_lit = ray(hit_pos, v3d_sub(lit_pos, hit_pos));
	ray_to_lit.origin = v3d_add(ray_to_lit.origin, \
						v3d_smult(ray_to_lit.dir, EPSILON));
	sqrmag_to_lit = v3d_sqrmag(v3d_sub(lit_pos, hit_pos));
	hit.is_hit = 0;
	hit.hit_idx = -1;
	idx = -1;
	node = rt->obj_list->head;
	while (++idx < rt->obj_list->size)
	{
		hit = get_hit_by_o_type(ray_to_lit, node, idx);
		if ((hit.is_hit == 1) && (hit.sqrmag < sqrmag_to_lit))
			return (1);
		node = node->next;
	}
	return (0);
}
