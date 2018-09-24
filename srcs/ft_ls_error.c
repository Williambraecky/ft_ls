/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:21:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/24 13:25:28 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_exit_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	ft_ls_perror(char *filename)
{
	ft_printf_fd(2, "ls: %s: %s\n", filename, strerror(errno));
}

void	ft_exit_usage(t_ls *ls, char c)
{
	ft_printf_fd(2, "ls: illegal option -- %c\n", c);
	ft_printf_fd(2, "%s\n", "usage: ls [-ABCFGHLOPRSTUWabcdef\
ghiklmnopqrstuwx1] [file ...]");
	free(ls);
	exit(1);
}

void	ft_fts_open_error(t_ls *ls)
{
	ft_printf_fd(2, "ls: fts_open: No such file or directory\n");
	free(ls);
	exit(1);
}
