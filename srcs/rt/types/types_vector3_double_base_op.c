/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_vector3_double_base_op.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 06:51:48 by moson             #+#    #+#             */
/*   Updated: 2024/04/28 06:51:49 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

t_vector3_double	v3d_add(t_vector3_double a, t_vector3_double b)
{
	return (v3d(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector3_double	v3d_sub(t_vector3_double a, t_vector3_double b)
{
	return (v3d(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector3_double	v3d_smult(t_vector3_double v, double s)
{
	return (v3d(v.x * s, v.y * s, v.z * s));
}
