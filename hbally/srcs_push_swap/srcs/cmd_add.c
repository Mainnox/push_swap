/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:47:16 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:01:11 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void		cmd_add(t_data *data, char *cmd_str)
{
	cmdlst_add(data, &(data->cmds), cmd_str);
	cmd_apply(data, cmd_str);
}
