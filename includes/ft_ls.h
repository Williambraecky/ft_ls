/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:21 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/17 15:26:31 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <errno.h>
# include "libft.h"

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;

typedef struct s_ls t_ls;
struct		s_ls
{
	size_t	options;
};

/*
** Options func
*/

int			ft_has_option(t_ls *ls, size_t option);
void		ft_set_option(t_ls *ls, size_t option);
void		ft_remove_option(t_ls *ls, size_t option);
void		ft_toggle_option(t_ls *ls, size_t option);

/*
** Utils func
*/

char		*ft_permstr(t_stat stat);
char		*ft_extract_time(time_t compared);
int			ft_dircmp(t_dirent *a, t_dirent *b);

#endif
