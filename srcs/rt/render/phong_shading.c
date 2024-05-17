/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:43:32 by moson             #+#    #+#             */
/*   Updated: 2024/05/14 15:23:11 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static t_ray	get_cam_ray(t_rt_dat *rt, int x, int y, double unit_dist)
{
	t_ray				cur_ray;
	t_vector3_double	unit_x;
	t_vector3_double	unit_y;

	cur_ray.origin = rt->cam->o_info.tr.position;
	cur_ray.dir = rt->cam->o_info.tr.forward[AXIS_Z];
	unit_x = v3d_smult(rt->cam->o_info.tr.forward[AXIS_X], \
						unit_dist * (0.5 - x + WIN_X / 2));
	unit_y = v3d_smult(rt->cam->o_info.tr.forward[AXIS_Y], \
						unit_dist * (0.5 - y + WIN_Y / 2));
	cur_ray.dir = v3d_add(cur_ray.dir, unit_x);
	cur_ray.dir = v3d_add(cur_ray.dir, unit_y);
	cur_ray.dir = v3d_norm(cur_ray.dir);
	return (cur_ray);
}

static t_rt_color	get_ambient(t_rt_dat *rt, t_node *node)
{
	t_rt_color	amb_col;
	t_rt_color	target_col;
	t_rt_color	res_col;

	if (rt->light_enable[0] == 0)
		return (rt_no_hit_col());
	amb_col = rt_col_mult(rt->amb->o_info.color, rt->amb->ratio);
	target_col = get_o_info(node)->color;
	res_col.r = (amb_col.r / 255.0) * target_col.r;
	res_col.g = (amb_col.g / 255.0) * target_col.g;
	res_col.b = (amb_col.b / 255.0) * target_col.b;
	res_col.a = target_col.a;
	return (res_col);
}

static t_rt_color	get_diffuse(t_rt_dat *rt, t_hit hit, t_o_lit *lit)
{
	t_rt_color			col;
	t_vector3_double	hit_to_lit;
	double				dot_res;

	if (rt->light_enable[1] == 0)
		return (rt_color(0, 0, 0, 0.0));
	col = rt_color(0, 0, 0, 0.0);
	hit_to_lit = v3d_norm(v3d_sub(lit->o_info.tr.position, hit.point));
	dot_res = v3d_dot(hit.hit_normal, hit_to_lit);
	if (dot_res < 0)
	{
		dot_res = 0;
	}
	col = rt_col_mult(lit->o_info.color, dot_res * lit->ratio * DIFFUSE_CONST);
	return (col);
}

static t_rt_color	get_specular(t_rt_dat *rt, t_hit hit, t_o_lit *lit)
{
	t_rt_color			col;
	t_vector3_double	reflect;
	double				dot_res;

	if (rt->light_enable[2] == 0)
		return (rt_color(0, 0, 0, 0.0));
	col = rt_color(0, 0, 0, 0.0);
	reflect = get_reflection_vector(\
				v3d_sub(hit.point, lit->o_info.tr.position), hit.hit_normal);
	dot_res = v3d_dot(v3d_norm(reflect), \
			v3d_norm(v3d_sub(rt->cam->o_info.tr.position, hit.point)));
	if (dot_res < 0)
		dot_res = 0;
	col = rt_col_mult(lit->o_info.color, \
						pow(dot_res, SPECULAR_CONST) * \
						lit->ratio / v3d_sqrmag(reflect) * \
						pow(SPECULAR_MAX_DIST, 2));
	return (col);
}

t_rt_color	apply_phong_shading(t_rt_dat *rt, int x, int y, double unit_dist)
{
	t_rt_color	col;
	t_hit		hit;
	t_node		*node;
	t_o_lit		*lit;

	rt->ray_buf[y][x] = get_cam_ray(rt, x, y, unit_dist);
	hit = get_first_hit(rt, rt->ray_buf[y][x], -1);
	if (hit.is_hit == 0)
		return (rt_no_hit_col());
	node = get_node(rt->obj_list, hit.hit_idx);
	col = get_ambient(rt, node);
	node = rt->lit_list->head;
	while (node != NULL)
	{
		lit = ((t_o_lit *)(node->item));
		if (!has_shadow(rt, lit->o_info.tr.position, hit.point))
		{
			col = rt_col_add(get_diffuse(rt, hit, lit), \
								v3i(col.r, col.g, col.b));
			col = rt_col_add(get_specular(rt, hit, lit), \
								v3i(col.r, col.g, col.b));
		}
		node = node->next;
	}
	return (col);
}
