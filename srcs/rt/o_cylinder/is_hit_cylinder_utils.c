/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_cylinder_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:09:52 by moson             #+#    #+#             */
/*   Updated: 2024/05/02 21:09:53 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

//	If no point intersects returns -1
int	get_min_point_idx(t_ray ray_local, t_vector3_double *points, double *sqr_mag, int valid_bits)
{
	int	cnt;
	int	min_idx;

	cnt = -1;
	while (++cnt < 4)
	{
		if ((((1 << cnt) & valid_bits) >> cnt) == 1)
			sqr_mag[cnt] = vector3_sqrmagnitude(vector3_sub(points[cnt], ray_local.origin));
		else
			sqr_mag[cnt] = -1.0;
	}
	cnt = 0;
	min_idx = 0;
	while (++cnt < 4)
	{
		if (sqr_mag[min_idx] == -1.0)
			min_idx = cnt;
		else if ((sqr_mag[cnt] != -1.0) && (sqr_mag[cnt] < sqr_mag[min_idx]))
			min_idx = cnt;
	}
	if (sqr_mag[min_idx] == -1.0)
		return (-1);
	return (min_idx);
}
