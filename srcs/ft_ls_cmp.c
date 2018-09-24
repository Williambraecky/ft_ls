/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:32:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/24 13:19:04 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_timecmp(t_file *a, t_file *b)
{
	if (a->stat.st_mtimespec.tv_sec > b->stat.st_mtimespec.tv_sec)
		return (-1);
	else if (a->stat.st_mtimespec.tv_sec == b->stat.st_mtimespec.tv_sec)
		return (ft_dircmp(a, b));
	return (1);
}

int		ft_dircmp(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name));
}

int		ft_revdircmp(t_file *a, t_file *b)
{
	return (-ft_dircmp(a, b));
}

int		ft_revtimecmp(t_file *a, t_file *b)
{
	return (-ft_timecmp(a, b));
}

int		ft_argcmp(char *a, char *b)
{
	int		a_exists;
	int		b_exists;
	t_stat	stat;

	a_exists = lstat(a, &stat) != -1;
	b_exists = lstat(b, &stat) != -1;
	if (!a_exists && b_exists)
		return (-1);
	else if (!b_exists && a_exists)
		return (1);
	if (ft_is_dir(a) && !ft_is_dir(b))
		return (1);
	else if (!ft_is_dir(a) && ft_is_dir(b))
		return (-1);
	return (ft_strcmp(a, b));
}
