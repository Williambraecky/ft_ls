/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:15:03 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/18 12:05:13 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_permgetspecial(mode_t value)
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

/*
** TODO: Read attributes
*/

char	*ft_permstr(t_stat stat)
{
	char str[12];

	str[11] = '\0';
	str[0] = ft_permgetspecial(stat.st_mode);
	str[1] = stat.st_mode & S_IRUSR ? 'r' : '-';
	str[2] = stat.st_mode & S_IWUSR ? 'w' : '-';
	str[3] = stat.st_mode & S_IXUSR ? 'x' : '-';
	str[4] = stat.st_mode & S_IRGRP ? 'r' : '-';
	str[5] = stat.st_mode & S_IWGRP ? 'w' : '-';
	str[6] = stat.st_mode & S_IXGRP ? 'x' : '-';
	str[7] = stat.st_mode & S_IROTH ? 'r' : '-';
	str[8] = stat.st_mode & S_IWOTH ? 'w' : '-';
	str[9] = stat.st_mode & S_IXOTH ? 'x' : '-';
	str[10] = ' ';
	return (ft_strdup(str));
}
