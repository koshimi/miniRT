/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:46:51 by moson             #+#    #+#             */
/*   Updated: 2023/03/26 22:46:54 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	int		cnt;

	res = 0x0;
	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] == (char)c)
		{
			res = (char *)&s[cnt];
			break ;
		}
		cnt++;
	}
	if ((char)c == '\0')
		res = (char *)&s[cnt];
	return (res);
}
