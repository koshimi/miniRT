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

//	is_hit_cylinder_utils.c
int	get_min_point_idx(t_ray ray_local, t_vector3_double *points, double *sqr_mag, int valid_bits);

//	returns valid bits
static int	get_circle_intersect_points(t_ray ray, double r, double h, t_vector3_double *points)
{
	t_vector3_double	o;
	t_vector3_double	d;
	double				t1;
	double				t2;
	int					valid_bits;

	o = ray.origin;
	d = ray.dir;
	t1 = (h / 2 - o.y) / d.y;
	t2 = (-h / 2 - o.y) / d.y;
	valid_bits = 0;
	points[2] = vector3_double(o.x + t1 * d.x, h / 2, o.z + t1 * d.z);
	points[3] = vector3_double(o.x + t2 * d.x, -h / 2, o.z + t2 * d.z);
	if ((0 <= t1) && (pow(points[2].x, 2) + pow(points[2].z, 2) <= pow(r, 2)))
		valid_bits += 0b0100;
	if ((0 <= t2) && (pow(points[3].x, 2) + pow(points[3].z, 2) <= pow(r, 2)))
		valid_bits += 0b1000;
	return (valid_bits);
}

//	returns valid bits
static int	get_side_intersect_points(t_vector3_double abc, t_ray ray, double h, t_vector3_double *points)
{
	double	disc;
	double	t1;
	double	t2;
	int		valid_bits;

	valid_bits = 0;
	disc = sqrt(pow(abc.y, 2) - 4 * abc.x * abc.z);
	t1 = (-abc.y + disc) / (2 * abc.x);
	points[0] = vector3_double(ray.origin.x + t1 * ray.dir.x, ray.origin.y \
		+ t1 * ray.dir.y, ray.origin.z + t1 * ray.dir.z);
	t2 = (-abc.y - disc) / (2 * abc.x);
	points[1] = vector3_double(ray.origin.x + t2 * ray.dir.x, ray.origin.y \
		+ t2 * ray.dir.y, ray.origin.z + t2 * ray.dir.z);
	if ((-h / 2 <= points[0].y) && (points[0].y <= h / 2) && (0 < t1))
		valid_bits += 0b01;
	if ((-h / 2 <= points[1].y) && (points[1].y <= h / 2) && (0 < t2))
		valid_bits += 0b10;
	return (valid_bits);
}

static int	has_side_intersect_points(t_ray ray_local, double r, t_vector3_double *abc)
{
	t_vector3_double	d;
	t_vector3_double	o;

	d = ray_local.dir;
	o = ray_local.origin;
	abc->x = pow(d.x, 2) + pow(d.z, 2);
	abc->y = 2 * (o.x * d.x + o.z * d.z);
	abc->z = pow(o.x, 2) + pow(o.z, 2) - pow(r, 2);
	if (abc->x == 0 || pow(abc->y, 2) - 4 * abc->x * abc->z < 0)
		return (0);
	if (d.x == 0 && d.z == 0)
		return (0);
	return (1);
}

//	returns min_idx
static int	get_point_idx(t_vector3_double *ret, t_ray ray_local, double r, double h)
{
	t_vector3_double	abc;
	t_vector3_double	points[4];
	int					valid_bits;
	double				sqr_mag[4];
	int					min_idx;

	valid_bits = 0;
	if (has_side_intersect_points(ray_local, r, &abc) != 0)
		valid_bits += get_side_intersect_points(abc, ray_local, h, points);
	if (ray_local.dir.y != 0)
		valid_bits += get_circle_intersect_points(ray_local, r, h, points);
	min_idx = get_min_point_idx(ray_local, points, sqr_mag, valid_bits);
	if (min_idx == -1)
		return (-1);
	*ret = points[min_idx];
	return (min_idx);
}

t_hit	is_hit_cylinder(t_ray ray_world, const t_o_cyl *cyl, unsigned int obj_idx)
{
	t_hit				hit;
	t_ray				ray_local;
	t_vector3_double	point_local;
	int					hit_idx;

	hit.is_hit = 0;
	ray_local = get_local_ray(ray_world, cyl->o_info.tr);
	hit.ray = ray_world;
	hit_idx = get_point_idx(&point_local, ray_local, cyl->radius, cyl->height);
	if (hit_idx == -1)
		return (hit);
	hit.is_hit = 1;
	hit.point = rt_ltow(point_local, cyl->o_info.tr);
	if (2 <= hit_idx)
		// hit.hit_normal = vector3_smult(ray_world.dir, 1 - 2 * (hit_idx == 3));
		hit.hit_normal = vector3_smult(cyl->o_info.tr.forward[AXIS_Y], 1 - 2 * (hit_idx == 3));
	else
		hit.hit_normal = vector3_normalized(vector3_sub(point_local, vector3_double(0, point_local.y, 0)));
	hit.sqrmag = vector3_sqrmagnitude(vector3_sub(hit.point, ray_world.origin));
	hit.hit_obj_idx = obj_idx;
	return (hit);
}
