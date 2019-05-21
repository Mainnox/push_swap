/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:01:01 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:01:16 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libpsviz.h"
#include "keys.h"

static void		set_startup_values(t_data *data)
{
	data->cmds.at_start = 1;
	data->win->batch = 1;
	data->cmds.step_number = 0;
	data->win->autosolve = NO_AUTOSOLVE;
	data->win->reverse = NO_REVERSE;
	data->win->prevmove = NO_PREVMOVE;
	data->win->nextmove = NEXTMOVE;
	data->win->hide_nextmove = NOHIDE_NEXTMOVE;
}

void			startup_viz(t_data *data)
{
	get_ref(data);
	start_window(data, data->win);
	set_startup_values(data);
	render(data, data->win);
	mlx_hook(data->win->self_id, KEYPRESS, KEYPRESSMASK, &keyboard_hooks, data);
	mlx_loop_hook(data->win->mlx_id, &loop_hook, data);
	mlx_loop(data->win->mlx_id);
}
