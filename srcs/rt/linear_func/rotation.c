/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:07:12 by moson             #+#    #+#             */
/*   Updated: 2024/04/08 17:07:13 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

t_vector3_double	tr_rotate(const t_vector3_double *v, \
					char axis, double sin_x, double cos_x)
{
	t_vector3_double	res;

	res.x = v->x;
	res.y = v->y;
	res.z = v->z;
	if (axis == 'x' || axis == 'X')
	{
		res.y = (int)(cos_x * v->y - sin_x * v->z);
		res.z = (int)(sin_x * v->y + cos_x * v->z);
	}
	else if (axis == 'y' || axis == 'Y')
	{
		res.x = (int)(cos_x * v->x + sin_x * v->z);
		res.z = (int)(cos_x * v->z - sin_x * v->x);
	}
	else if (axis == 'z' || axis == 'Z')
	{
		res.x = (int)(cos_x * v->x - sin_x * v->y);
		res.y = (int)(sin_x * v->x + cos_x * v->y);
	}
	return (res);
}
