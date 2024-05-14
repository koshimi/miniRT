/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:20:30 by moson             #+#    #+#             */
/*   Updated: 2024/04/14 06:20:31 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static void	set_o_info(t_o_info *info, const t_sphere_input *input)
{
	info->o_type = OTYPE_SPHERE;
	info->tr = tr();
	info->tr.position = input->position;
	info->color = input->color;
	return ;
}

t_o_sph	*new_sphere(const t_sphere_input *input)
{
	t_o_sph	*res;

	res = (t_o_sph *)malloc(sizeof(t_o_sph) * 1);
	if (res == NULL)
		return (NULL);
	res->o_type = OTYPE_SPHERE;
	set_o_info(&res->o_info, input);
	res->radius = input->diameter / 2.0;
	return (res);
}
