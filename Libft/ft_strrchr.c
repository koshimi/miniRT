/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:56:28 by moson             #+#    #+#             */
/*   Updated: 2023/03/26 22:56:29 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		cnt;

	res = 0x0;
	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] == (char)c)
			res = (char *)&s[cnt];
		cnt++;
	}
	if ((char)c == '\0')
		res = (char *)&s[cnt];
	return (res);
}
