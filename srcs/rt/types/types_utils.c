/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:50:37 by moson             #+#    #+#             */
/*   Updated: 2024/04/06 13:50:39 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

t_vector2_int	v2i(int x, int y)
{
	t_vector2_int	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vector3_int	v3i(int x, int y, int z)
{
	t_vector3_int	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector3_double	v3d(double x, double y, double z)
{
	t_vector3_double	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_transform	tr(void)
{
	t_transform	tr;

	tr.position = v3d(0.0, 0.0, 0.0);
	tr.forward[AXIS_X] = v3d(1.0, 0.0, 0.0);
	tr.forward[AXIS_Y] = v3d(0.0, 1.0, 0.0);
	tr.forward[AXIS_Z] = v3d(0.0, 0.0, 1.0);
	tr.scale = v3d(1.0, 1.0, 1.0);
	return (tr);
}

t_ray	ray(t_vector3_double origin, t_vector3_double dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = v3d_norm(dir);
	return (ray);
}
