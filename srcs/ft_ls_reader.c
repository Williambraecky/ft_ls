/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:37:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/18 16:59:20 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_getpath(const char *dir)
{
	char	*str;

	if (*(dir + ft_strlen(dir) - 1) == '/')
		str = ft_strdup(dir);
	else
		str = ft_strjoin(dir, "/");
	return (str);
}

void	ft_iterate_dir(t_lsdir dir)
{
	t_list *list;

	list = dir.list;
	if (dir.ls->print == ft_print_dir_long)
		ft_printf("total %d\n", dir.b_total);
	while (list != NULL)
	{
		dir.ls->print(list->content, dir);
		list = list->next;
	}
	if (dir.ls->print == ft_print_dir)
		ft_printf("\n");
}

void	ft_reset_lsdir(t_lsdir *dir)
{
	dir->u_len = 0;
	dir->g_len = 0;
	dir->s_len = 0;
	dir->l_len = 0;
	dir->n_len = 0;
	dir->b_total = 0;
	dir->list = NULL;
}

void	ft_dir_calc_max(t_lsdir *dir, t_file *file)
{
	dir->b_total += file->stat.st_blocks;
	dir->u_len = ft_max(dir->u_len, ft_strlen(file->pwd.pw_name));
	dir->g_len = ft_max(dir->g_len, ft_strlen(file->grp.gr_name));
	dir->s_len = ft_max(dir->s_len, ft_intlen(file->stat.st_size) + 1);
	dir->l_len = ft_max(dir->l_len, ft_intlen(file->stat.st_nlink) + 1);
	dir->n_len = ft_max(dir->n_len, ft_strlen(file->dirent.d_name) + 1);
}

/*
** TODO: Better iteration taking account of flags; predefine comparator for
** good sorting
*/

void	ft_readdir(t_ls *ls, const char *dir)
{
	DIR		*dirp;
	t_dir	*dp;
	t_lsdir	lsdir;
	t_file	lsfile;

	dirp = opendir(dir);
	if (dirp == NULL)
		return perror(ls->prog_name);
	lsdir.ls = ls;
	lsdir.path = ft_getpath(dir);
	ft_reset_lsdir(&lsdir);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] == '.' && !(ls->options & FT_LS_HIDDEN))
			continue ;
		lsfile.dirent = *dp;
		lsfile.fullpath = ft_strjoin(lsdir.path, dp->d_name);
		lstat(lsfile.fullpath, &(lsfile.stat));
		lsfile.pwd = *(getpwuid(lsfile.stat.st_uid));
		lsfile.grp = *(getgrgid(lsfile.stat.st_gid));
		ft_dir_calc_max(&lsdir, &lsfile);
		ft_lstsortinsert(&(lsdir.list), &lsfile, sizeof(lsfile), ls->cmp);
	}
	closedir(dirp);
	ft_iterate_dir(lsdir);
}
