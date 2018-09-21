/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:09:00 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 18:56:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_dir_long(t_file *file, t_lsdir dir)
{
	char	buffer[1023];
	char	*perm;
	char	*time;

	perm = ft_permstr(file);
	time = ft_extract_time(file->stat.st_mtimespec.tv_sec);
	ft_printf("%s%*d %-*s  %-*s ", perm, dir.l_len, file->stat.st_nlink,
			dir.u_len, file->pwd, dir.g_len, file->grp);
	if (perm[0] == 'b' || perm[0] == 'c')
		ft_printf(" %*d, %*d ", dir.mj_len, major(file->stat.st_rdev),
				dir.mi_len, minor(file->stat.st_rdev));
	else
		ft_printf(" %*lld ", dir.s_len + (dir.mi_len != 0), file->stat.st_size);
	ft_printf("%s %s", time, file->name);
	if ((file->stat.st_mode & S_IFMT) == S_IFLNK)
		ft_printf(" -> %.*s", readlink(file->fullpath, buffer, 1023), buffer);
	ft_printf("\n");
	free(perm);
	free(time);
}

void	ft_print_dir(t_file *file, t_lsdir dir)
{
	if (dir.ls->options & FT_LS_LINE)
		ft_printf("%s\n", file->name);
	else
		ft_printf("%-*s", dir.n_len, file->name);
}
