/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 13:14:54 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*g_ls;

/*
** TODO: print files first and then directories
*/

int		main(int argc, const char *argv[])
{
	int		i;

	g_ls = ft_read_options(argc, argv);
	i = 1;
	while (i < argc && ft_is_option_format(argv[i]))
		i++;
	ft_strsort((char **)argv + i, argc - i, ft_argcmp);
	if (i == argc)
		ft_readdir(g_ls, ".", 0);
	while (i < argc)
		ft_readdir(g_ls, argv[i++], 1);
	free(g_ls);
	return (0);
}
