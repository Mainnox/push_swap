/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:47:21 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:03:05 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"

void			cmd_print(t_cmds *cmds)
{
	t_cmdlst	*elem;

	elem = cmds->start;
	while (elem)
	{
		ft_printf("%s\n", elem->cmd);
		elem = elem->next;
	}
}
