/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_get_inverse_3x3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:16:10 by moson             #+#    #+#             */
/*   Updated: 2024/04/22 21:16:12 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

double	get_cofactor(t_mat_3x3_double mat, int i, int j)
{
	int	l;
	int	r;
	int	u;
	int	d;

	l = 1 * (j == 0);
	r = 2 - (1 * (j == 2));
	u = 1 * (i == 0);
	d = 2 - (1 * (i == 2));
	return ((pow(-1, i + j)) * \
		(mat.a[u][l] * mat.a[d][r] - mat.a[u][r] * mat.a[d][l]));
}

t_mat_3x3_double	mat_3x3_inverse(t_mat_3x3_double mat)
{
	t_mat_3x3_double	adj;
	double				det;
	int					i;
	int					j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			adj.a[i][j] = get_cofactor(mat, j, i);
	}
	det = mat.a[0][0] * adj.a[0][0] + \
		mat.a[0][1] * adj.a[1][0] + \
		mat.a[0][2] * adj.a[2][0];
	if (det == 0.0)
		det = EPSILON;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			adj.a[i][j] /= det;
	}
	return (adj);
}
