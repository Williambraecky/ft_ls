/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_reader_recursive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:21:22 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 17:55:06 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_post_iterate_dir(t_lsdir dir)
{
	t_list	*list;
	t_list	*tmp;
	char	*str;

	list = dir.list;
	dir.ls->printed++;
	while (list != NULL)
	{
		str = ((t_file *)(list->content))->name;
		if (dir.ls->options & FT_LS_RECURSIVE
				&& S_ISDIR(((t_file *)(list->content))->stat.st_mode)
				&& !ft_strequ(str, ".") && !ft_strequ(str, ".."))
			ft_readdir(dir.ls, ((t_file *)list->content)->fullpath, 1);
		tmp = list;
		list = list->next;
		ft_lstdelone(&tmp, ft_del_file);
	}
	free(dir.path);
}
