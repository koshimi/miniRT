/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:04:54 by moson             #+#    #+#             */
/*   Updated: 2024/04/14 01:04:55 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static void	set_o_info(t_o_info *info, const t_light_input *input)
{
	info->o_type = OTYPE_LIGHT;
	info->tr = tr();
	info->tr.position = input->position;
	info->color = input->color;
	return ;
}

t_o_lit	*new_light(const t_light_input *input)
{
	t_o_lit	*res;

	res = (t_o_lit *)malloc(sizeof(t_o_lit) * 1);
	if (res == NULL)
		return (NULL);
	res->o_type = OTYPE_LIGHT;
	set_o_info(&res->o_info, input);
	res->ratio = input->ratio;
	return (res);
}
