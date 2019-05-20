/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_applylist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:46:17 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:00:06 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"

void				cmd_applylist(t_data *data)
{
	t_cmdlst		*elem;

	elem = data->cmds.start;
	while (elem)
	{
		cmd_apply(data, elem->cmd);
		elem = elem->next;
	}
}
