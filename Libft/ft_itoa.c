/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:31:36 by moson             #+#    #+#             */
/*   Updated: 2023/03/31 11:31:38 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_n_arr(long long n, char *ref_res_rev)
{
	int		size;
	int		sign;

	size = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (9 < n)
	{
		ref_res_rev[size] = '0' + (n % 10);
		n /= 10;
		size++;
	}
	ref_res_rev[size] = '0' + n;
	size++;
	if (sign == -1)
	{
		ref_res_rev[size] = '-';
		size++;
	}
	ref_res_rev[size] = '\0';
	return ;
}

char	*ft_itoa(int n)
{
	char		*res;
	char		ref_res_rev[12];
	size_t		len;
	size_t		cnt;

	get_n_arr((long long)n, ref_res_rev);
	len = ft_strlen(ref_res_rev);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res != NULL)
	{
		cnt = 0;
		while (cnt < len)
		{
			res[cnt] = ref_res_rev[len - cnt - 1];
			cnt++;
		}
		res[cnt] = '\0';
	}
	return (res);
}
