/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:51:03 by moson             #+#    #+#             */
/*   Updated: 2023/03/29 05:51:04 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	cnt;

	cnt = 0;
	while (set[cnt] != '\0')
	{
		if (c == set[cnt])
			return (1);
		cnt++;
	}
	return (0);
}

static size_t	get_nonset_start(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	cnt;

	s1_len = ft_strlen(s1);
	cnt = 0;
	while (cnt < s1_len && is_set(s1[cnt], set))
		cnt++;
	return (cnt);
}

static size_t	get_nonset_end(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	cnt;

	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (0);
	else
		cnt = s1_len - 1;
	while (0 < cnt && is_set(s1[cnt], set))
		cnt--;
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	start = get_nonset_start(s1, set);
	end = get_nonset_end(s1, set);
	if (end < start)
		res = ft_substr(s1, (unsigned int)start, 0);
	else
		res = ft_substr(s1, (unsigned int)start, end - start + 1);
	return (res);
}
