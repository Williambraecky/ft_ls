/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:56:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/17 15:40:30 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_extract_time(time_t compared)
{
	time_t	now;
	char	*str;
	char	*timestr;

	now = time(NULL);
	timestr = ctime(&compared);
	if (compared > now || compared < now - (6 * 30 * 24 * 3600))
	{
		timestr[10] = '\0';
		timestr[7] = '\0';
		timestr[24] = '\0';
		str = ft_strformat("%s %s  %s", timestr + 8, timestr + 4, timestr + 20);
	}
	else
	{
		timestr[10] = '\0';
		timestr[7] = '\0';
		timestr[16] = '\0';
		str = ft_strformat("%s %s %s", timestr + 8, timestr + 4, timestr + 11);
	}
	return (ft_strtolower(str));
}
