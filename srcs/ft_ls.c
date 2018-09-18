/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:43:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/18 17:27:57 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, const char *argv[])
{
	t_ls	*ls;
	int		i;

	ls = ft_read_options(argc, argv);
	i = 1;
	while (i < argc && ft_is_option_format(argv[i]))
		i++;
	if (i == argc)
		ft_readdir(ls, ".");
	while (i < argc)
		ft_readdir(ls, argv[i++]);
	free(ls);
	return 0;
}
