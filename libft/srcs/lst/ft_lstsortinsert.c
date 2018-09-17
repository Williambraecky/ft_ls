/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortinsert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:38:03 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/17 14:27:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsortinsert(t_list **begin_list, void *content, size_t size,
		int (*cmp)())
{
	t_list *current;
	t_list *insert;
	t_list *prev;

	current = *begin_list;
	insert = ft_lstnew(content, size);
	if (current == NULL || cmp(current->content, content) > 0)
	{
		insert->next = current;
		*begin_list = insert;
		return ;
	}
	prev = current;
	current = current->next;
	while (current != NULL)
	{
		if (cmp(current->content, content) > 0)
		{
			prev->next = insert;
			insert->next = current;
			return ;
		}
		prev = current;
		current = current->next;
	}
	prev->next = insert;
}
