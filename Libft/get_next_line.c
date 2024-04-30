/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:13:13 by moson             #+#    #+#             */
/*   Updated: 2023/05/31 01:13:14 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(const char *s);
size_t	get_lf_idx(const char *str);
char	*gnl_substr(const char *s, size_t start, size_t len);
char	*realloc_join(char *str1, char *str2);

static char	*free_n_ret_null(char **a, char **b, char **c, char **d)
{
	if (a != NULL)
	{
		free(*a);
		*a = NULL;
	}
	if (b != NULL)
	{
		free(*b);
		*b = NULL;
	}
	if (c != NULL)
	{
		free(*c);
		*c = NULL;
	}
	if (d != NULL)
	{
		free(*d);
		*d = NULL;
	}
	return (NULL);
}

static char	*has_no_lf(int fd, char **stored, char **buf)
{
	ssize_t	read_bytes;
	char	*stored_new;
	char	*res;

	*buf = (char *)malloc(BUFFER_SIZE + 1);
	if (*buf == NULL)
		return (free_n_ret_null(stored, 0, 0, 0));
	read_bytes = read(fd, (void *)(*buf), BUFFER_SIZE);
	if (read_bytes == -1)
		return (free_n_ret_null(stored, buf, 0, 0));
	else if (read_bytes == 0)
	{
		res = gnl_substr(*stored, 0, gnl_strlen(*stored));
		free_n_ret_null(stored, buf, 0, 0);
		return (res);
	}
	(*buf)[read_bytes] = '\0';
	stored_new = realloc_join(*stored, *buf);
	free_n_ret_null(stored, buf, 0, 0);
	if (stored_new == NULL)
		return (NULL);
	*stored = stored_new;
	return (get_next_line(fd));
}

static char	*when_stored(int fd, char **stored, char **buf)
{
	size_t	lf_idx;
	size_t	stored_len;
	char	*res;
	char	*stored_new;

	lf_idx = get_lf_idx(*stored);
	stored_len = gnl_strlen(*stored);
	if (lf_idx < stored_len)
	{
		res = gnl_substr(*stored, 0, lf_idx + 1);
		if (res == NULL)
			return (free_n_ret_null(stored, 0, 0, 0));
		stored_new = NULL;
		if (stored_len - (lf_idx + 1) != 0)
		{
			stored_new = gnl_substr(*stored, lf_idx + 1, \
			stored_len - (lf_idx + 1));
			if (stored_new == NULL)
				return (free_n_ret_null(stored, &res, 0, 0));
		}
		free(*stored);
		*stored = stored_new;
		return (res);
	}
	return (has_no_lf(fd, stored, buf));
}

char	*get_next_line(int fd)
{
	static char	*stored;
	ssize_t		read_bytes;
	char		*buf;

	if (stored != NULL)
		return (when_stored(fd, &stored, &buf));
	else
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		read_bytes = read(fd, (void *)buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (free_n_ret_null(&buf, 0, 0, 0));
		buf[read_bytes] = '\0';
		stored = buf;
		return (get_next_line(fd));
	}
}
