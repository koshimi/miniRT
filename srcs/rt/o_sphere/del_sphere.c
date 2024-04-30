/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:20:40 by moson             #+#    #+#             */
/*   Updated: 2024/04/14 06:20:41 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

void	del_sphere(t_o_sph **ptr)
{
	t_o_sph	*sph;

	sph = *ptr;
	if (sph != NULL)
		free(sph);
	*ptr = NULL;
	return ;
}
