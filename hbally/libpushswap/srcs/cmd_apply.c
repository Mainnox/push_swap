/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:46:34 by hbally            #+#    #+#             */
/*   Updated: 2019/02/07 14:53:35 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"

void		cmd_apply(t_data *data, char *cmd)
{
	size_t	i;

	i = 0;
	while (i < CMDINDEX_SIZE)
	{
		if (!ft_strcmp(cmd, data->index[i].cmd_str))
		{
			data->index[i].cmd_ft(&(data->a), &(data->b), data->index[i].flag);
			break ;
		}
		i++;
	}
}

void		cmd_reverse(t_data *data, char *cmd)
{
	char	cmd_tmp[4];

	ft_strcpy(cmd_tmp, cmd);
	if (cmd_tmp[0] == 's')
		cmd_apply(data, cmd_tmp);
	else
	{
		if (cmd_tmp[1] == 'r' && cmd_tmp[2] != '\0')
			ft_memmove(cmd_tmp, &(cmd_tmp[1]), 3);
		else if (cmd_tmp[0] == 'p')
			cmd_tmp[1] = cmd_tmp[1] == 'a' ? 'b' : 'a';
		else
		{
			ft_memmove(&(cmd_tmp[1]), cmd_tmp, 3);
			cmd_tmp[0] = 'r';
		}
		cmd_apply(data, cmd_tmp);
	}
}
