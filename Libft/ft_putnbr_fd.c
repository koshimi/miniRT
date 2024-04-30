/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:00:03 by moson             #+#    #+#             */
/*   Updated: 2023/03/31 16:00:05 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((-1) * n, fd);
		return ;
	}
	else if (9 < n)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &("0123456789"[n % 10]), 1);
		return ;
	}
	else
	{
		write(fd, &("0123456789"[n]), 1);
		return ;
	}
}
