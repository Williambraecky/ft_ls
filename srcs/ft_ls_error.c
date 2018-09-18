/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:21:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/18 12:53:56 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_exit_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

void	ft_exit_usage(t_ls *ls, char c)
{
	ft_printf_fd(2, "ft_ls: illegal option -- %c\n", c);
	ft_printf_fd(2, "%s\n", FT_LS_USAGE);
	free(ls);
	exit(0);
}
