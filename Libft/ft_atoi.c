/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 07:17:29 by moson             #+#    #+#             */
/*   Updated: 2023/03/27 07:17:31 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	count;
	int	sign;
	int	result;

	count = 0;
	sign = 1;
	result = 0;
	while ((8 < str[count] && str[count] < 14) || str[count] == 32)
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while ('0' <= str[count] && str[count] <= '9')
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (sign * result);
}
