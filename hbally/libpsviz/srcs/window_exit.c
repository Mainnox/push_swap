/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:34:22 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:23:24 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libpushswap.h"
#include "libft.h"

static void		exit_stackcheck(t_data *data)
{
	if (data->cmds.step_number == 0 && !data->cmds.pos && data->cmds.start)
		data->cmds.pos = data->cmds.start;
	while (data->cmds.pos)
	{
		cmd_apply(data, data->cmds.pos->cmd);
		data->cmds.pos = data->cmds.pos->next;
	}
	ft_printf(check_stacks(&(data->a), &(data->b)) ? "OK\n" : "KO\n");
}

void			exit_window(t_data *data, t_win *win, t_err error)
{
	if (win->mlx_id && win->img.self_id)
		mlx_destroy_image(win->mlx_id, win->img.self_id);
	if (win->mlx_id && win->self_id)
		mlx_destroy_window(win->mlx_id, win->self_id);
	if (error)
		clean_exit(error, data);
	else
	{
		exit_stackcheck(data);
		clean_exit(NO_ERROR, data);
	}
}
