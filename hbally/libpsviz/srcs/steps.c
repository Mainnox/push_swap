/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:13:25 by hbally            #+#    #+#             */
/*   Updated: 2019/01/30 17:13:35 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "libpsviz.h"

void			previous_step(t_data *data)
{
	if (!data->cmds.at_start)
	{
		if (!data->cmds.pos)
		{
			data->cmds.pos = data->cmds.end;
			data->cmds.at_end = 0;
		}
		else
			data->cmds.pos = data->cmds.pos->prev;
		if (data->cmds.pos == NULL)
			data->cmds.at_start = 1;
		if (data->cmds.pos)
		{
			cmd_reverse(data, data->cmds.pos->cmd);
			data->cmds.step_number--;
			render(data, data->win);
		}
	}
}

void			next_step(t_data *data)
{
	if (!data->cmds.at_end)
	{
		if (!data->cmds.pos)
		{
			data->cmds.pos = data->cmds.start;
			data->cmds.at_start = 0;
		}
		cmd_apply(data, data->cmds.pos->cmd);
		data->cmds.step_number++;
		data->cmds.pos = data->cmds.pos->next;
		if (data->cmds.pos == NULL)
			data->cmds.at_end = 1;
		render(data, data->win);
	}
}
