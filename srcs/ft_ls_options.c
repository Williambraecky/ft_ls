/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:13:20 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/21 13:14:58 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_has_option(t_ls *ls, size_t option)
{
	return (ls->options & option);
}

void	ft_set_option(t_ls *ls, size_t option)
{
	ls->options |= option;
}

void	ft_remove_option(t_ls *ls, size_t option)
{
	if (ft_has_option(ls, option))
		ft_toggle_option(ls, option);
}

void	ft_toggle_option(t_ls *ls, size_t option)
{
	ls->options ^= option;
}
