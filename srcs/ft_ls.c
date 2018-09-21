/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 18:24:37 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*g_ls;

/*
** TODO: print files first and then directories
** TODO: skip non directories + print errors while iterating
** TODO: make sure it doesn't read directory if only files are used
** TODO: make sure files result is well formated
*/

int		main(int argc, const char *argv[])
{
	int		i;
	int		after;

	g_ls = ft_read_options(argc, argv);
	i = 1;
	while (i < argc && ft_is_option_format(argv[i]))
		i++;
	ft_strsort((char **)argv + i, argc - i, ft_argcmp);
	after = ft_handle_params(i, argc, argv, g_ls);
	if (after == i && after == argc)
		ft_readdir(g_ls, ".", 0);
	while (after < argc)
		ft_readdir(g_ls, argv[after++], 1);
	free(g_ls);
	return (0);
}
