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

t_vector2_int	vector2_int(int x, int y)
{
	t_vector2_int	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vector3_int	vector3_int(int x, int y, int z)
{
	t_vector3_int	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector3_double	vector3_double(double x, double y, double z)
{
	t_vector3_double	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_transform	transform(void)
{
	t_transform	tr;

	tr.position = vector3_double(0.0, 0.0, 0.0);
	tr.forward[AXIS_X] = vector3_double(1.0, 0.0, 0.0);
	tr.forward[AXIS_Y] = vector3_double(0.0, 1.0, 0.0);
	tr.forward[AXIS_Z] = vector3_double(0.0, 0.0, 1.0);
	tr.scale = vector3_double(1.0, 1.0, 1.0);
	return (tr);
}

t_ray	ray(t_vector3_double origin, t_vector3_double dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = vector3_normalized(dir);
	return (ray);
}
