/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:34:46 by moson             #+#    #+#             */
/*   Updated: 2024/04/30 05:34:47 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static int	get_closer_point(t_vector3_double abc, t_ray ray, t_vector3_double *point)
{
	double				disc;
	double				t1;
	double				t2;
	t_vector3_double	p1;
	t_vector3_double	p2;

	disc = sqrt(pow(abc.y, 2) - 4 * abc.x * abc.z);
	t1 = (-abc.y + disc) / (2 * abc.x);
	p1 = vector3_double(ray.origin.x + t1 * ray.dir.x, ray.origin.y \
		+ t1 * ray.dir.y, ray.origin.z + t1 * ray.dir.z);
	t2 = (-abc.y - disc) / (2 * abc.x);
	p2 = vector3_double(ray.origin.x + t2 * ray.dir.x, ray.origin.y \
		+ t2 * ray.dir.y, ray.origin.z + t2 * ray.dir.z);
	if (t1 <= 0 && t2 <= 0)
		return (0);
	else if (t1 <= 0)
		*point = p2;
	else if (t2 <= 0)
		*point = p1;
	else if (t1 < t2)
		*point = p1;
	else
		*point = p2;
	return (1);
}

//	TODO: is radius local?
static int	get_point(t_vector3_double *ret, t_ray ray_local, double r)
{
	t_vector3_double	abc;
	t_vector3_double	d;
	t_vector3_double	o;

	d = ray_local.dir;
	o = ray_local.origin;
	abc.x = pow(d.x, 2) + pow(d.y, 2) + pow(d.z, 2);
	abc.y = 2 * (o.x * d.x + o.y * d.y + o.z * d.z);
	abc.z = pow(o.x, 2) + pow(o.y, 2) + pow(o.z, 2) - pow(r, 2);
	if (abc.x == 0 || pow(abc.y, 2) - 4 * abc.x * abc.z < 0)
		return (0);
	if (get_closer_point(abc, ray_local, ret) == 0)
		return (0);
	return (1);
}

t_hit	is_hit_sphere(t_ray ray_world, const t_o_sph *sph, unsigned int obj_idx)
{
	t_hit				hit;
	t_ray				ray_local;
	t_vector3_double	point_local;

	hit.is_hit = 0;
	ray_local = get_local_ray(ray_world, sph->o_info.tr);
	hit.ray = ray_world;
	if (get_point(&point_local, ray_local, sph->radius) == 0)
		return (hit);
	hit.is_hit = 1;
	hit.point = rt_ltow(point_local, sph->o_info.tr);
	hit.hit_normal = vector3_normalized(vector3_sub \
		(hit.point, rt_ltow(vector3_double(0, 0, 0), sph->o_info.tr)));
	hit.sqrmag = vector3_sqrmagnitude(vector3_sub(hit.point, ray_world.origin));
	hit.hit_obj_idx = obj_idx;
	return (hit);
}
