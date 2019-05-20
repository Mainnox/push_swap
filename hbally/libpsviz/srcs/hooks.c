/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:16:46 by hbally            #+#    #+#             */
/*   Updated: 2019/02/01 17:16:28 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"
#include "libpushswap.h"
#include "keys.h"

int				loop_hook(void *param)
{
	int16_t		i;
	t_data		*data;

	i = 0;
	data = (t_data*)param;
	if (data->win->reverse == REVERSE)
	{
		while (i++ < data->win->batch)
			previous_step(data);
		render(data, data->win);
	}
	if (data->win->autosolve == AUTOSOLVE)
	{
		while (i++ < data->win->batch)
			next_step(data);
		render(data, data->win);
	}
	if (data->cmds.at_end)
		data->win->autosolve = NO_AUTOSOLVE;
	if (data->cmds.at_start)
		data->win->reverse = NO_REVERSE;
	return (0);
}

void			autosteps_hooks(int keycode, t_data *data)
{
	if (keycode == SP_KEY)
	{
		data->win->autosolve *= -1;
		data->win->prevmove = NO_PREVMOVE;
	}
	if (keycode == R_KEY)
	{
		data->win->reverse *= -1;
		data->win->prevmove = PREVMOVE;
	}
	if (keycode != N_KEY && !(keycode >= K1_KEY && keycode <= K5_KEY))
	{
		if (keycode != SP_KEY)
			data->win->autosolve = NO_AUTOSOLVE;
		if (keycode != R_KEY)
			data->win->reverse = NO_REVERSE;
	}
}

void			manualsteps_hooks(int keycode, t_data *data)
{
	int16_t		i;

	i = 0;
	if (keycode == LEFT_KEY)
	{
		data->win->prevmove = PREVMOVE;
		while (i++ < data->win->batch)
			previous_step(data);
	}
	if (keycode == RIGHT_KEY)
	{
		data->win->prevmove = NO_PREVMOVE;
		while (i++ < data->win->batch)
			next_step(data);
	}
	if (keycode == N_KEY)
	{
		if (data->win->prevmove == PREVMOVE && data->win->nextmove == NEXTMOVE)
		{
			data->win->prevmove = NO_PREVMOVE;
			render(data, data->win);
		}
		else
			data->win->nextmove *= -1;
	}
}

void			batch_hooks(int keycode, t_data *data)
{
	if (keycode == K1_KEY)
		data->win->batch = 1;
	if (keycode == K2_KEY)
		data->win->batch = 2;
	if (keycode == K3_KEY)
		data->win->batch = 3;
	if (keycode == K4_KEY)
		data->win->batch = 4;
	if (keycode == K5_KEY)
		data->win->batch = 5;
	if (data->win->batch != 1)
		data->win->hide_nextmove = HIDE_NEXTMOVE;
	else
		data->win->hide_nextmove = NOHIDE_NEXTMOVE;
}

int				keyboard_hooks(int keycode, void *param)
{
	t_data		*data;

	data = (t_data*)param;
	if (keycode == ESC_KEY)
		exit_window(data, data->win, NO_ERROR);
	if (data->cmds.start)
	{
		manualsteps_hooks(keycode, data);
		autosteps_hooks(keycode, data);
		batch_hooks(keycode, data);
		render(data, data->win);
	}
	return (0);
}
