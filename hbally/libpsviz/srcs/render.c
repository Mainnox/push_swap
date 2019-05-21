/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:56:40 by hbally            #+#    #+#             */
/*   Updated: 2019/02/25 16:05:44 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libpsviz.h"
#include "libft.h"

uint8_t		show_nextmove(t_data *data)
{
	if (data->cmds.start
			&& data->win->nextmove == NEXTMOVE
			&& data->win->prevmove == NO_PREVMOVE
			&& (data->win->hide_nextmove == NOHIDE_NEXTMOVE
					|| data->cmds.step_number == 0))
	{
		if (data->cmds.pos)
			return (1);
		if (!data->cmds.pos && data->cmds.step_number == 0)
			return (1);
	}
	return (0);
}

void		render(t_data *data, t_win *win)
{
	char	*cmd;

	draw_background(win);
	cmd = NULL;
	if (!show_nextmove(data))
	{
		add_stack(data, win->a_anchor, &(data->a), 0);
		add_stack(data, win->b_anchor, &(data->b), 0);
	}
	else
	{
		cmd = data->cmds.pos ? data->cmds.pos->cmd : data->cmds.start->cmd;
		add_stack(data, win->a_anchor, &(data->a),
					(cmd[0] == 's' && !(cmd[1] == 'b')));
		add_stack(data, win->b_anchor, &(data->b),
					(cmd[0] == 's' && !(cmd[1] == 'a')));
		add_lastmove(data, win, cmd);
	}
	mlx_put_image_to_window(win->mlx_id, win->self_id, win->img.self_id, 0, 0);
	draw_ui(data, win, &(data->cmds), cmd);
}
