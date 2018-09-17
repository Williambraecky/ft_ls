/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:15:03 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/17 14:16:38 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_permstr(t_stat stat)
{
	char str[11];

	str[10] = '\0';
	str[0] = S_ISDIR(stat.st_mode) ? 'd' : '-';
	str[1] = stat.st_mode & S_IRUSR ? 'r' : '-';
	str[2] = stat.st_mode & S_IWUSR ? 'w' : '-';
	str[3] = stat.st_mode & S_IXUSR ? 'x' : '-';
	str[4] = stat.st_mode & S_IRGRP ? 'r' : '-';
	str[5] = stat.st_mode & S_IWGRP ? 'w' : '-';
	str[6] = stat.st_mode & S_IXGRP ? 'x' : '-';
	str[7] = stat.st_mode & S_IROTH ? 'r' : '-';
	str[8] = stat.st_mode & S_IWOTH ? 'w' : '-';
	str[9] = stat.st_mode & S_IXOTH ? 'x' : '-';
	return (ft_strdup(str));
}
