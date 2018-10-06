/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:05:21 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/06 16:30:36 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_handle_params(int start, int argc, const char *argv[], t_ls *ls)
{
	t_lsdir	lsdir;
	t_file	lsfile;

	ft_bzero(&lsdir, sizeof(lsdir));
	lsdir.ls = ls;
	lsdir.path = ft_strnew(0);
	while (start < argc && !ft_is_dir((char *)argv[start]))
	{
		lsfile.name = ft_strdup(argv[start]);
		lsfile.fullpath = ft_strdup(argv[start++]);
		if (lstat(lsfile.fullpath, &(lsfile.stat)) == -1)
		{
			ft_ls_perror(lsfile.name);
			ls->errors++;
			continue ;
		}
		lsfile.pwd = ft_get_pwd_name(lsfile.stat.st_uid, ls);
		lsfile.grp = ft_get_grp_name(lsfile.stat.st_gid, ls);
		ft_dir_calc_max(&lsdir, &lsfile);
		ft_lstsortinsert(&(lsdir.list), &lsfile, sizeof(lsfile), ls->cmp);
	}
	if (lsdir.list != NULL)
		ft_iterate_dir(lsdir);
	return (start);
}
