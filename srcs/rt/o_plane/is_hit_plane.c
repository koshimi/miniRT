/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:06:30 by moson             #+#    #+#             */
/*   Updated: 2024/04/28 07:06:31 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

t_hit	is_hit_plane(t_ray ray_world, const t_o_pl *pl, unsigned int obj_idx)
{
	t_hit				hit;
	t_ray				ray_local;
	t_vector3_double	point_local;
	double				t;

	hit.is_hit = 0;
	ray_local = get_local_ray(ray_world, pl->o_info.tr);
	hit.ray = ray_world;
	if (ray_local.dir.z == 0.0 || (-ray_local.origin.z / ray_local.dir.z <= 0))
		return (hit);
	hit.is_hit = 1;
	t = -ray_local.origin.z / ray_local.dir.z;
	point_local = v3d(ray_local.origin.x + t * ray_local.dir.x, \
								ray_local.origin.y + t * ray_local.dir.y, 0);
	hit.point = rt_ltow(point_local, pl->o_info.tr);
	hit.hit_normal = pl->o_info.tr.forward[AXIS_Z];
	if (ray_local.origin.z < 0)
		hit.hit_normal = v3d_smult(hit.hit_normal, -1);
	hit.sqrmag = v3d_sqrmag(v3d_sub(hit.point, ray_world.origin));
	hit.hit_idx = obj_idx;
	return (hit);
}
