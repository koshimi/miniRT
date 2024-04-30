/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:38:23 by moson             #+#    #+#             */
/*   Updated: 2023/04/04 08:38:24 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_all(int flag, t_list *head, void (*del)(void *), void *content)
{
	if (flag)
	{
		ft_lstclear(&head, del);
		del(content);
	}
	return (flag);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*item;
	void	*content;
	int		free_flag;

	head = NULL;
	free_flag = 0;
	while (lst != NULL)
	{
		content = f(lst->content);
		item = ft_lstnew(content);
		if (item == NULL)
		{
			free_flag = 1;
			break ;
		}
		if (head == NULL)
			head = item;
		else
			ft_lstadd_back(&head, item);
		lst = lst->next;
	}
	if (free_all(free_flag, head, del, content))
		return (NULL);
	return (head);
}
