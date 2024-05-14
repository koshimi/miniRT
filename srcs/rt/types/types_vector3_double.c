/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_vector3_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:04:44 by moson             #+#    #+#             */
/*   Updated: 2024/04/11 18:04:45 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

double	v3d_sqrmag(t_vector3_double v)
{
	return (pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

double	v3d_mag(t_vector3_double v)
{
	return (sqrt(v3d_sqrmag(v)));
}

t_vector3_double	v3d_norm(t_vector3_double v)
{
	double				mag;

	mag = v3d_mag(v);
	if (mag == 0.0)
		return (v3d(v.x, v.y, v.z));
	else
		return (v3d(v.x / mag, v.y / mag, v.z / mag));
}

int	is_null_v3d(t_vector3_double v)
{
	if (v3d_sqrmag(v) == 0.0)
		return (1);
	else
		return (0);
}

//	If v is axis-vector, return ['x', 'y', 'z']
//	else return 0
char	is_axis_v3d(t_vector3_double v)
{
	if (v.x == 0.0 && v.y == 0.0 && v.z != 0.0)
		return ('z');
	else if (v.x == 0.0 && v.y != 0.0 && v.z == 0.0)
		return ('y');
	else if (v.x != 0.0 && v.y == 0.0 && v.z == 0.0)
		return ('x');
	else
		return (0);
}
