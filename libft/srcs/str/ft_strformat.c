/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:13:35 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/14 14:16:30 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strformat(const char *format, ...)
{
	va_list	list[2];
	t_flags	*flags;
	char	*str;

	if (format == NULL || !(flags = ft_new_flags()))
		return (NULL);
	va_start(list[0], format);
	va_copy(list[1], list[0]);
	ft_parse_printf((char *)format, list, flags);
	ft_printf_flush(flags);
	va_end(list[0]);
	va_end(list[1]);
	str = flags->str;
	free(flags);
	return (str);
}
