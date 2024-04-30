/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:47:47 by moson             #+#    #+#             */
/*   Updated: 2023/03/31 07:47:49 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_item_count(char const *s, char c)
{
	size_t	item_count;
	size_t	cnt;
	int		is_prev_c;

	item_count = 0;
	cnt = 0;
	is_prev_c = 1;
	while (s[cnt] != '\0')
	{
		if (is_prev_c)
		{
			if (s[cnt] != c)
			{
				item_count++;
				is_prev_c = 0;
			}
		}
		else
		{
			if (s[cnt] == c)
				is_prev_c = 1;
		}
		cnt++;
	}
	return (item_count);
}

static char	*get_item(char const *s, char c, size_t *ref_cur_idx)
{
	unsigned int	start;
	size_t			len;

	while (s[(*ref_cur_idx)] == c)
		(*ref_cur_idx)++;
	start = (*ref_cur_idx);
	len = 0;
	while (s[(*ref_cur_idx) + len] != c && s[(*ref_cur_idx) + len] != '\0')
		len++;
	(*ref_cur_idx) += len;
	return (ft_substr(s, start, len));
}

static void	free_all(char **res, size_t null_item_idx)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < null_item_idx)
	{
		free(res[cnt]);
		cnt++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	size_t	item_count;
	size_t	cnt;
	size_t	ref_cur_idx;
	char	**res;

	item_count = get_item_count(s, c);
	cnt = 0;
	ref_cur_idx = 0;
	res = (char **)malloc(sizeof(char *) * (item_count + 1));
	if (res != NULL)
	{
		while (cnt < item_count)
		{
			res[cnt] = get_item(s, c, &ref_cur_idx);
			if (res[cnt] == NULL)
			{
				free_all(res, cnt);
				return (NULL);
			}
			cnt++;
		}
		if (cnt == item_count)
			res[cnt] = NULL;
	}
	return (res);
}
