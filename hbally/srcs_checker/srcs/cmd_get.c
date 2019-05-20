/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:46:11 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:00:18 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "libft.h"

void			cmd_get(t_data *data)
{
	char		*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr("sa sb pa pb ra rb rra rrb ss rr rrr", line)
				&& !ft_strchr(line, ' ') && ft_strlen(line) > 1)
		{
			cmdlst_add(data, &(data->cmds), line);
			ft_memdel((void**)&line);
		}
		else
		{
			ft_memdel((void**)&line);
			clean_exit(GETARG_BADFORMAT, data);
		}
	}
}
