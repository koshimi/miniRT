/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:13:04 by moson             #+#    #+#             */
/*   Updated: 2023/05/31 01:13:06 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(const char *s)
{
	size_t	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (*(s + length) != '\0')
		length++;
	return (length);
}

size_t	get_lf_idx(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == '\n')
			return (count);
		count++;
	}
	return (count);
}

char	*gnl_substr(const char *s, size_t start, size_t len)
{
	size_t	s_len;
	char	*res;
	size_t	cnt;

	s_len = gnl_strlen(s);
	if (start + len > s_len)
	{
		if (s_len + 1 > (size_t)start)
			len = s_len + 1 - (size_t)start;
		else
			len = 1;
	}
	else
		len = len + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	cnt = 0;
	while (cnt + 1 < len)
	{
		res[cnt] = s[(size_t)start + cnt];
		cnt++;
	}
	res[cnt] = '\0';
	return (res);
}

char	*realloc_join(char *str1, char *str2)
{
	char	*res;
	size_t	str1_len;
	size_t	str2_len;
	size_t	cnt;

	str1_len = gnl_strlen(str1);
	str2_len = gnl_strlen(str2);
	res = (char *)malloc(str1_len + str2_len + 1);
	if (res == NULL)
		return (NULL);
	cnt = 0;
	while (cnt < str1_len)
	{
		res[cnt] = str1[cnt];
		cnt++;
	}
	while (cnt < str2_len + str1_len)
	{
		res[cnt] = str2[cnt - str1_len];
		cnt++;
	}
	res[cnt] = '\0';
	return (res);
}
