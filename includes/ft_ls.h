/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:21 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 18:21:16 by wbraeckm         ###   ########.fr       */
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
# define MINORBITS 20
# define MINORMASK ((1U << MINORBITS) - 1)
# define MAJOR(dev) ((unsigned int) ((dev) >> MINORBITS))
# define MINOR(dev) ((unsigned int) ((dev) & MINORMASK))

typedef struct stat		t_stat;
typedef struct dirent	t_dir;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;

typedef struct s_ls		t_ls;
struct		s_ls
{
	size_t	options;
	char	*prog_name;
	int		printed;
	int		(*cmp)();
	void	(*print)();
};

typedef struct s_file	t_file;
struct		s_file
{
	char	*fullpath;
	char	*name;
	t_stat	stat;
	char	*pwd;
	char	*grp;
};

/*
** l_len = link len
** u_len = user len
** g_len = group len
** s_len = size len
** n_len = name len;
** mj_len = major len;
** mi_len = minor len;
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
	int		mj_len;
	int		mi_len;
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

char		*ft_permstr(t_file *file);
char		*ft_extract_time(time_t compared);
void		ft_exit_error(char *str);
void		ft_exit_usage(t_ls *ls, char c);
void		ft_ls_perror(char *file);
int			ft_timecmp(t_file *a, t_file *b);
int			ft_dircmp(t_file *a, t_file *b);
int			ft_revdircmp(t_file *a, t_file *b);
int			ft_revtimecmp(t_file *a, t_file *b);
int			ft_argcmp(char *a, char *b);
int			ft_is_dir(char *str);
void		ft_del_file(void *content, size_t size);
char		*ft_get_pwd_name(uid_t uid);
char		*ft_get_grp_name(gid_t git);
void		ft_reset_lsdir(t_lsdir *dir);
void		ft_dir_calc_max(t_lsdir *dir, t_file *file);

/*
** Reading func
*/

void		ft_readdir(t_ls *ls, const char *dir, int printdir);
void		ft_print_dir(t_file *file, t_lsdir dir);
void		ft_print_dir_long(t_file *file, t_lsdir dir);
void		ft_print_dir_name(t_ls *ls, char *str, int printdir);
void		ft_iterate_dir(t_lsdir dir);
void		ft_post_iterate_dir(t_lsdir dir);
int			ft_handle_params(int start, int argc, const char *argv[], t_ls *ls);

#endif
