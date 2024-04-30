/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:28:43 by moson             #+#    #+#             */
/*   Updated: 2023/03/18 03:28:44 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

static int	islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (isupper(c) || islower(c))
		return (1);
	else
		return (0);
}
