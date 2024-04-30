/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:12:41 by moson             #+#    #+#             */
/*   Updated: 2024/04/04 09:12:42 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

//	TODO: Is del_rt_dat() needed?
int	mlx_event_destroy(void *param)
{
	param = NULL;
	exit(0);
	return (0);
}
