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

double	vector3_sqrmagnitude(t_vector3_double v)
{
	return (pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

double	vector3_magnitude(t_vector3_double v)
{
	return (sqrt(vector3_sqrmagnitude(v)));
}

t_vector3_double	vector3_normalized(t_vector3_double v)
{
	double				mag;

	mag = vector3_magnitude(v);
	if (mag == 0.0)
		return (vector3_double(v.x, v.y, v.z));
	else
		return (vector3_double(v.x / mag, v.y / mag, v.z / mag));
}

int	is_null_vector3(t_vector3_double v)
{
	if (vector3_sqrmagnitude(v) == 0.0)
		return (1);
	else
		return (0);
}

//	If v is axis-vector, return ['x', 'y', 'z']
//	else return 0
char	is_axis_vector3(t_vector3_double v)
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
