/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:32:17 by moson             #+#    #+#             */
/*   Updated: 2024/04/06 14:32:18 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

void	del_camera(t_o_cam **ptr)
{
	t_o_cam	*cam;

	cam = *ptr;
	if (cam != NULL)
		free(cam);
	*ptr = NULL;
	return ;
}
