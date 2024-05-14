/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:31:09 by moson             #+#    #+#             */
/*   Updated: 2024/04/06 13:31:10 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static void	set_o_info(t_o_info *info, const t_ambient_lighting_input *input)
{
	info->o_type = OTYPE_AMBIENT;
	info->tr = tr();
	info->color = input->color;
	return ;
}

t_o_amb	*new_ambient(const t_ambient_lighting_input *input)
{
	t_o_amb	*res;

	res = (t_o_amb *)malloc(sizeof(t_o_amb) * 1);
	if (res == NULL)
		return (NULL);
	res->o_type = OTYPE_AMBIENT;
	set_o_info(&res->o_info, input);
	res->ratio = input->ratio;
	return (res);
}
