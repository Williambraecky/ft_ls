/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:21 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/18 16:57:46 by wbraeckm         ###   ########.fr       */
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

# define FT_LS_USAGE "usage: ./ft_ls [-Ralrt] [file ...]"
# define FT_LS_LONG (1 << 0)
# define FT_LS_RECURSIVE (1 << 1)
# define FT_LS_HIDDEN (1 << 2)
# define FT_LS_REVERSE (1 << 3)
# define FT_LS_TIME (1 << 4)

typedef struct stat		t_stat;
typedef struct dirent	t_dir;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;

typedef struct s_ls		t_ls;
struct		s_ls
{
	size_t	options;
	char	*prog_name;
	int		(*cmp)();
	void	(*print)();
};

typedef struct s_file	t_file;
struct		s_file
{
	char	*fullpath;
	t_dir	dirent;
	t_stat	stat;
	t_pwd	pwd;
	t_grp	grp;
};

/*
** l_len = link len
** u_len = user len
** g_len = group len
** s_len = size len
** n_len = name len;
*/

typedef struct s_lsdir	t_lsdir;
struct		s_lsdir
{
	t_ls	*ls;
	t_list	*list;
	char	*path;
	int		b_total;
	int		u_len;
	int		g_len;
	int		s_len;
	int		l_len;
	int		n_len;
};

/*
** Options func
*/

int			ft_has_option(t_ls *ls, size_t option);
void		ft_set_option(t_ls *ls, size_t option);
void		ft_remove_option(t_ls *ls, size_t option);
void		ft_toggle_option(t_ls *ls, size_t option);
t_ls		*ft_read_options(int argc, const char *argv[]);
int			ft_is_option_format(const char *str);

/*
** Utils func
*/

char		*ft_permstr(t_stat stat);
char		*ft_extract_time(time_t compared);
void		ft_exit_error(char *str);
void		ft_exit_usage(t_ls *ls, char c);
int			ft_timecmp(t_file *a, t_file *b);
int			ft_dircmp(t_file *a, t_file *b);
int			ft_revdircmp(t_file *a, t_file *b);
int			ft_revtimecmp(t_file *a, t_file *b);
int			ft_is_dir(char *str);

/*
** Reading func
*/

void		ft_readdir(t_ls *ls, const char *dir);
void		ft_print_dir(t_file *file, t_lsdir dir);
void		ft_print_dir_long(t_file *file, t_lsdir dir);

#endif
