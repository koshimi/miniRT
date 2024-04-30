/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:46:50 by moson             #+#    #+#             */
/*   Updated: 2024/04/30 08:46:51 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static t_vector3_double	get_closer_point(double a, double b, double c, t_ray ray)
{
	double				disc;
	double				t;
	t_vector3_double	p1;
	t_vector3_double	p2;
	
	disc = sqrt(pow(b, 2) - 4 * a * c);
	t = (-b + disc) / (2 * a);
	p1 = vector3_double(ray.origin.x + t * ray.dir.x, ray.origin.y \
		+ t * ray.dir.y, ray.origin.z + t * ray.dir.z);
	t = (-b - disc) / (2 * a);
	p2 = vector3_double(ray.origin.x + t * ray.dir.x, ray.origin.y \
		+ t * ray.dir.y, ray.origin.z + t * ray.dir.z);
	if (vector3_sqrmagnitude(vector3_sub(ray.origin, p1)) \
		< vector3_sqrmagnitude(vector3_sub(ray.origin, p2)))
		return (p1);
	else
		return (p2);
}

static int	get_point(t_vector3_double *ret, t_ray ray_local, double r)
{
	double 				a;
	double 				b;
	double 				c;
	t_vector3_double	v;
	t_vector3_double	o;

	v = ray_local.dir;
	o = ray_local.origin;
	a = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
	b = 2 * (o.x * v.x + o.y * v.y + o.z * v.z);
	c = pow(o.x, 2) + pow(o.y, 2) + pow(o.z, 2) - pow(r, 2);
	if (a == 0 || pow(b, 2) - 4 * a * c < 0)
		return (0);
	*ret = get_closer_point(a, b, c, ray_local);
	return (1);
}

t_hit	is_hit_cylinder(t_ray ray_world, const t_o_cyl *cyl, unsigned int obj_idx)
{
	t_hit				hit;
	t_ray				ray_local;
	t_vector3_double	point_local;
	
	hit.is_hit = 0;
	ray_local = get_local_ray(ray_world, cyl->o_info.tr);
	hit.ray = ray_world;
	if (get_point(&point_local, ray_local, cyl->radius) == 0)
		return (hit);
	hit.is_hit = 1;
	hit.point = rt_ltow(point_local, cyl->o_info.tr);
	hit.hit_normal = vector3_normalized(vector3_sub \
		(hit.point, rt_ltow(vector3_double(0, 0, 0), cyl->o_info.tr)));
	hit.sqrmag = vector3_sqrmagnitude(vector3_sub(hit.point, ray_world.origin));
	hit.hit_obj_idx = obj_idx;
	return (hit);
}
