/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:15:03 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 13:15:03 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		ft_permgetspecial(mode_t value)
{
	value &= S_IFMT;
	if (value == S_IFIFO)
		return ('p');
	else if (value == S_IFCHR)
		return ('c');
	else if (value == S_IFBLK)
		return ('b');
	else if (value == S_IFLNK)
		return ('l');
	else if (value == S_IFSOCK)
		return ('s');
	else if (value == S_IFDIR)
		return ('d');
	return ('-');
}

static void	ft_usr_part(t_file *file, char str[12])
{
	t_stat stat;

	stat = file->stat;
	str[1] = stat.st_mode & S_IRUSR ? 'r' : '-';
	str[2] = stat.st_mode & S_IWUSR ? 'w' : '-';
	if (stat.st_mode & S_ISUID && !(stat.st_mode & S_IXUSR))
		str[3] = 'S';
	else if (stat.st_mode & S_ISUID && stat.st_mode & S_IXUSR)
		str[3] = 's';
	else
		str[3] = stat.st_mode & S_IXUSR ? 'x' : '-';
}

static void	ft_grp_part(t_file *file, char str[12])
{
	t_stat stat;

	stat = file->stat;
	str[4] = stat.st_mode & S_IRGRP ? 'r' : '-';
	str[5] = stat.st_mode & S_IWGRP ? 'w' : '-';
	if (stat.st_mode & S_ISGID && !(stat.st_mode & S_IXGRP))
		str[6] = 'S';
	else if (stat.st_mode & S_ISGID && stat.st_mode & S_IXGRP)
		str[6] = 's';
	else
		str[6] = stat.st_mode & S_IXGRP ? 'x' : '-';
}

static void	ft_oth_part(t_file *file, char str[12])
{
	t_stat stat;

	stat = file->stat;
	str[7] = stat.st_mode & S_IROTH ? 'r' : '-';
	str[8] = stat.st_mode & S_IWOTH ? 'w' : '-';
	if (stat.st_mode & S_ISVTX && !(stat.st_mode & S_IXOTH))
		str[9] = 'T';
	else if (stat.st_mode & S_ISVTX && stat.st_mode & S_IXOTH)
		str[9] = 't';
	else
		str[9] = stat.st_mode & S_IXOTH ? 'x' : '-';
}

char		*ft_permstr(t_file *file)
{
	t_stat	stat;
	char	str[12];
	char	buff[256];

	stat = file->stat;
	str[11] = '\0';
	str[0] = ft_permgetspecial(stat.st_mode);
	ft_usr_part(file, str);
	ft_grp_part(file, str);
	ft_oth_part(file, str);
	if (listxattr(file->fullpath, buff, 256, XATTR_SHOWCOMPRESSION) > 0)
		str[10] = '@';
	else
		str[10] = ' ';
	return (ft_strdup(str));
}
