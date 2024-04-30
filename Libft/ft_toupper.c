/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:01:41 by moson             #+#    #+#             */
/*   Updated: 2023/03/24 22:01:42 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ('a' <= uc && uc <= 'z')
		return (c - 'a' + 'A');
	else
		return (c);
}
