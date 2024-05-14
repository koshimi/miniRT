/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:58:09 by moson             #+#    #+#             */
/*   Updated: 2024/04/20 16:58:10 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

t_vector3_double	rt_linear_map( \
	const t_vector3_double v, const t_transform base)
{
	t_vector3_double	res;

	res.x = v3d_dot(v, base.forward[AXIS_X]);
	res.y = v3d_dot(v, base.forward[AXIS_Y]);
	res.z = v3d_dot(v, base.forward[AXIS_Z]);
	return (res);
}

t_vector3_double	rt_rlinear_map( \
	const t_vector3_double v, const t_transform base)
{
	t_mat_3x3_double	i_mat;
	t_vector3_double	res;

	i_mat = mat_3x3_inverse(mat_3x3_v3d \
		(base.forward[AXIS_X], base.forward[AXIS_Y], base.forward[AXIS_Z]));
	res.x = i_mat.a[0][0] * v.x + i_mat.a[0][1] * v.y + i_mat.a[0][2] * v.z;
	res.y = i_mat.a[1][0] * v.x + i_mat.a[1][1] * v.y + i_mat.a[1][2] * v.z;
	res.z = i_mat.a[2][0] * v.x + i_mat.a[2][1] * v.y + i_mat.a[2][2] * v.z;
	return (res);
}

//	WARNING: scale.* MUST NOT 0.0
t_vector3_double	rt_wtol(t_vector3_double w, t_transform tr)
{
	w.x -= tr.position.x;
	w.y -= tr.position.y;
	w.z -= tr.position.z;
	w.x /= tr.scale.x;
	w.y /= tr.scale.y;
	w.z /= tr.scale.z;
	return (rt_linear_map(w, tr));
}

//	WARNING: scale.* MUST NOT 0.0
t_vector3_double	rt_ltow(t_vector3_double l, t_transform tr)
{
	l = rt_rlinear_map(l, tr);
	l.x *= tr.scale.x;
	l.y *= tr.scale.y;
	l.z *= tr.scale.z;
	l.x += tr.position.x;
	l.y += tr.position.y;
	l.z += tr.position.z;
	return (l);
}
