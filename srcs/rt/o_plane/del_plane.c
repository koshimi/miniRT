/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:25:47 by moson             #+#    #+#             */
/*   Updated: 2024/04/17 17:25:48 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

void	del_plane(t_o_pl **ptr)
{
	t_o_pl	*pl;

	pl = *ptr;
	if (pl != NULL)
		free(pl);
	*ptr = NULL;
	return ;
}
