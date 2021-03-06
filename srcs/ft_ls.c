/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/24 13:27:50 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*g_ls;

int		main(int argc, const char *argv[])
{
	int		i;
	int		after;

	i = 1;
	g_ls = ft_read_options(argc, argv);
	while (i < argc && ft_is_option_format(argv[i]))
	{
		i++;
		if (ft_strequ(argv[i - 1], "--"))
			break ;
	}
	after = i;
	while (after < argc)
		if (ft_strlen(argv[after++]) == 0)
			ft_fts_open_error(g_ls);
	ft_strsort((char **)argv + i, argc - i, ft_argcmp);
	after = ft_handle_params(i, argc, argv, g_ls);
	if (after == i && after == argc)
		ft_readdir(g_ls, ".", 0);
	while (after < argc)
		ft_readdir(g_ls, argv[after++], g_ls->printed > 0 || after < argc ||
				g_ls->errors > 0);
	free(g_ls);
	return (errno != 0);
}
