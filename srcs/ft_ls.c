/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/17 14:18:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_dir(t_list *list)
{
	struct dirent	*dp;
	struct stat		d_stat;
	struct passwd	*pwd;
	struct group	*grp;
	char			*perm;

	dp = list->content;
	stat(dp->d_name, &d_stat);
	perm = ft_permstr(d_stat);
	pwd = getpwuid(d_stat.st_uid);
	grp = getgrgid(d_stat.st_gid);
	ft_printf("%s %3d %s  %s %6lld %s\n", perm, d_stat.st_nlink,
			pwd->pw_name, grp->gr_name, d_stat.st_size, dp->d_name);
	free(perm);
}

int		ft_dircmp(struct dirent *a, struct dirent *b)
{
	if (a->d_name[0] == '.' && b->d_name[0] != '.')
		return (-1);
	else if (a->d_name[0] == '.' && b->d_name[0] == '.')
		return (ft_strcmp(a->d_name, b->d_name));
	else if (a->d_name[0] != '.' && b->d_name[0] == '.')
		return (1);
	return (ft_strcmp(a->d_name, b->d_name));
}

int		ft_revdircmp(struct dirent *a, struct dirent *b)
{
	return (-ft_dircmp(a, b));
}

int main(int argc, const char *argv[])
{
	(void)argc;
	(void)argv;
	DIR *dirp = opendir(".");
	t_list *lst = NULL;
	if (dirp == NULL)
		return (0);
	struct dirent *dp;
	while ((dp = readdir(dirp)) != NULL)
		ft_lstsortinsert(&lst, dp, sizeof(*dp), ft_revdircmp);
	ft_lstiter(lst, ft_print_dir);
	(void)closedir(dirp);
	return 0;
}
