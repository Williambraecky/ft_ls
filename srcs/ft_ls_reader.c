/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:37:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 18:23:49 by wbraeckm         ###   ########.fr       */
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
	t_list	*list;

	list = dir.list;
	if (dir.ls->print == ft_print_dir_long && ft_lstlen(list) > 0
			&& ft_strlen(dir.path) != 0)
		ft_printf("total %d\n", dir.b_total);
	while (list != NULL)
	{
		dir.ls->print(list->content, dir);
		list = list->next;
	}
	if (dir.ls->print == ft_print_dir)
		ft_printf("\n");
	ft_post_iterate_dir(dir);
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
	dir->mj_len = 0;
	dir->mi_len = 0;
}

void	ft_dir_calc_max(t_lsdir *dir, t_file *file)
{
	dir->b_total += file->stat.st_blocks;
	dir->u_len = ft_max(dir->u_len, ft_strlen(file->pwd));
	dir->g_len = ft_max(dir->g_len, ft_strlen(file->grp));
	dir->s_len = ft_max(dir->s_len,
			ft_intlen(file->stat.st_size) + dir->mi_len + dir->mj_len);
	dir->l_len = ft_max(dir->l_len, ft_intlen(file->stat.st_nlink) + 1);
	dir->n_len = ft_max(dir->n_len, ft_strlen(file->name) + 1);
	if (S_ISBLK(file->stat.st_mode) || S_ISCHR(file->stat.st_mode))
	{
		dir->mj_len = ft_max(dir->mj_len,
				ft_intlen(major(file->stat.st_rdev)) + 1);
		dir->mi_len = ft_max(dir->mi_len,
				ft_intlen(minor(file->stat.st_rdev)));
	}
}

void	ft_readdir(t_ls *ls, const char *dir, int printdir)
{
	DIR		*dirp;
	t_dir	*dp;
	t_lsdir	lsdir;
	t_file	lsfile;

	ft_print_dir_name(ls, (char *)dir, printdir);
	if ((dirp = opendir(dir)) == NULL)
		return (ft_ls_perror((char *)dir));
	ft_reset_lsdir(&lsdir);
	lsdir.ls = ls;
	lsdir.path = ft_getpath(dir);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] == '.' && !(ls->options & FT_LS_HIDDEN))
			continue ;
		lsfile.name = ft_strdup(dp->d_name);
		lsfile.fullpath = ft_strjoin(lsdir.path, dp->d_name);
		lstat(lsfile.fullpath, &(lsfile.stat));
		lsfile.pwd = ft_get_pwd_name(lsfile.stat.st_uid);
		lsfile.grp = ft_get_grp_name(lsfile.stat.st_gid);
		ft_dir_calc_max(&lsdir, &lsfile);
		ft_lstsortinsert(&(lsdir.list), &lsfile, sizeof(lsfile), ls->cmp);
	}
	closedir(dirp);
	ft_iterate_dir(lsdir);
}
