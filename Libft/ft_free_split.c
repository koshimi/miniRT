/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:25:25 by moson             #+#    #+#             */
/*   Updated: 2023/08/14 23:25:27 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(void ***input)
{
	void	**split;
	size_t	cnt;

	split = *input;
	cnt = 0;
	while (split[cnt] != NULL)
	{
		free(split[cnt]);
		cnt++;
	}
	free(split);
	*input = NULL;
}
