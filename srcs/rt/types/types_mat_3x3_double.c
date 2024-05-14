/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_mat_3x3_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:22:56 by moson             #+#    #+#             */
/*   Updated: 2024/04/22 23:22:58 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

t_mat_3x3_double	mat_3x3_v3d( \
	t_vector3_double x, t_vector3_double y, t_vector3_double z)
{
	t_mat_3x3_double	res;

	res.a[0][0] = x.x;
	res.a[0][1] = x.y;
	res.a[0][2] = x.z;
	res.a[1][0] = y.x;
	res.a[1][1] = y.y;
	res.a[1][2] = y.z;
	res.a[2][0] = z.x;
	res.a[2][1] = z.y;
	res.a[2][2] = z.z;
	return (res);
}
