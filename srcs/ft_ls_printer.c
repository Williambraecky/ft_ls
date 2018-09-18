/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:09:00 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/18 16:34:59 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_dir_long(t_file *file, t_lsdir dir)
{
	char	buffer[256];
	char	*perm;
	char	*time;

	perm = ft_permstr(file->stat);
	time = ft_extract_time(file->stat.st_mtimespec.tv_sec);
	ft_printf("%s%*d %s  %s %*lld %s %s",
			perm, dir.l_len, file->stat.st_nlink,
			file->pwd.pw_name, file->grp.gr_name,
			dir.s_len, file->stat.st_size,
			time, file->dirent.d_name);
	if ((file->stat.st_mode & S_IFMT) == S_IFLNK)
		ft_printf(" -> %.*s", readlink(file->fullpath, buffer, 256), buffer);
	ft_printf("\n");
	free(perm);
	free(time);
}

void	ft_print_dir(t_file *file, t_lsdir dir)
{
	ft_printf("%-*s", dir.n_len, file->dirent.d_name);
}
