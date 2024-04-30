/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 03:12:35 by moson             #+#    #+#             */
/*   Updated: 2024/04/25 03:12:36 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

double	get_ray_unit_dist(t_vector3_double cam_z, int win_x, int fov)
{
	double	dist;

	cam_z = vector3_normalized(cam_z);
	if (fov == 90)
		fov -= 1;
	dist = 2.0 / win_x * tan((fov / 2) * M_PI / 180.0);
	return (dist);
}

t_ray	get_local_ray(t_ray ray_world, t_transform local_tr)
{
	t_ray	ray_local;

	ray_local.origin = rt_wtol(ray_world.origin, local_tr);
	ray_local.dir = vector3_normalized(vector3_sub(rt_wtol(ray_world.dir, local_tr), rt_wtol(vector3_double(0, 0, 0), local_tr)));
	return (ray_local);
}
