/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/24 12:24:00 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*g_ls;

int		main(int argc, const char *argv[])
{
	int		i;
	int		after;

	g_ls = ft_read_options(argc, argv);
	i = 1;
	while (i < argc && ft_is_option_format(argv[i]))
	{
		i++;
		if (ft_strequ(argv[i - 1], "--"))
			break ;
	}
	ft_strsort((char **)argv + i, argc - i, ft_argcmp);
	after = ft_handle_params(i, argc, argv, g_ls);
	if (after == i && after == argc)
		ft_readdir(g_ls, ".", 0);
	while (after < argc)
		ft_readdir(g_ls, argv[after++], g_ls->printed > 0 || after < argc);
	free(g_ls);
	return (errno != 0);
}
