/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:42:03 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/24 13:11:38 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_ls	*g_ls;

int			ft_is_dir(char *str)
{
	t_stat st;

	if (g_ls->options & FT_LS_LONG)
		lstat(str, &st);
	else
		stat(str, &st);
	return (S_ISDIR(st.st_mode));
}

void		ft_print_dir_name(t_ls *ls, char *str, int printdir)
{
	if (!printdir)
		return ;
	if (ls->printed++)
		ft_printf("\n");
	ft_printf("%s:\n", str);
}

void		ft_del_file(void *content, size_t size)
{
	t_file	*file;

	(void)size;
	file = (t_file *)content;
	free(file->fullpath);
	free(file->name);
	free(file->pwd);
	free(file->grp);
	free(file);
}

char		*ft_get_pwd_name(uid_t st_uid)
{
	t_pwd	*pwd;

	pwd = getpwuid(st_uid);
	if (pwd != NULL)
		return (ft_strdup(pwd->pw_name));
	return (ft_itoa(st_uid));
}

char		*ft_get_grp_name(gid_t st_gid)
{
	t_grp	*grp;

	grp = getgrgid(st_gid);
	if (grp != NULL)
		return (ft_strdup(grp->gr_name));
	return (ft_itoa(st_gid));
}
