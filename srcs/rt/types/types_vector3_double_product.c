/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_vector3_double_product.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:12:39 by moson             #+#    #+#             */
/*   Updated: 2024/04/13 21:12:40 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

double	v3d_dot(t_vector3_double a, t_vector3_double b)
{
	double	res;

	res = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (res);
}

t_vector3_double	v3d_cross(t_vector3_double a, t_vector3_double b)
{
	t_vector3_double	res;

	res.x = (a.y * b.z) - (a.z * b.y);
	res.y = - (a.x * b.z) + (a.z * b.x);
	res.z = (a.x * b.y) - (a.y * b.x);
	return (res);
}
