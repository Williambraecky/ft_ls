/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_options_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:19:12 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/18 16:55:52 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	g_optionchar[] =
{
	'l',
	'a',
	'r',
	'R',
	't',
	'\0'
};

static long	g_flags[] =
{
	FT_LS_LONG,
	FT_LS_HIDDEN,
	FT_LS_REVERSE,
	FT_LS_RECURSIVE,
	FT_LS_TIME
};

int		ft_is_option_format(const char *str)
{
	return (str[0] == '-' && ft_strlen(str) > 1);
}

void	ft_read_optionstr(t_ls *ls, const char *str)
{
	int i;

	str++;
	while (*str)
	{
		i = 0;
		if (ft_strchr(g_optionchar, *str) == NULL)
			ft_exit_usage(ls, *str);
		while (g_optionchar[i])
		{
			if (g_optionchar[i] == *str)
				ls->options |= g_flags[i];
			i++;
		}
		str++;
	}
}

t_ls	*ft_read_options(int argc, const char *argv[])
{
	t_ls	*ls;
	int		i;

	if (!(ls = ft_memalloc(sizeof(*ls))))
		ft_exit_error("Could not malloc");
	i = 1;
	while (i < argc && ft_is_option_format(argv[i]))
		ft_read_optionstr(ls, argv[i++]);
	if (ls->options & FT_LS_TIME)
		ls->cmp = ls->options & FT_LS_REVERSE ? ft_revtimecmp : ft_timecmp;
	else if (ls->options & FT_LS_REVERSE)
		ls->cmp = ft_revdircmp;
	else
		ls->cmp = ft_dircmp;
	ls->print = ls->options & FT_LS_LONG ? ft_print_dir_long : ft_print_dir;
	ls->prog_name = (char *)argv[0];
	return (ls);
}
