/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:01:36 by hbally            #+#    #+#             */
/*   Updated: 2019/02/25 16:05:43 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"
#include "libft.h"
#include "colors.h"
#include "mlx.h"

static void		draw_ui_nextmove(t_win *win, char *cmd)
{
	if (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "ss"))
	{
		mlx_string_put(win->mlx_id, win->self_id, win->a_top.x - 20,
						win->a_top.y - 40, MOVE_COLOR, "swap");
	}
	if (!ft_strcmp(cmd, "sb") || !ft_strcmp(cmd, "ss"))
	{
		mlx_string_put(win->mlx_id, win->self_id, win->b_top.x - 20,
							win->b_top.y - 40, MOVE_COLOR, "swap");
	}
}

int				draw_ui(t_data *data, t_win *win, t_cmds *cmds, char *cmd)
{
	char		*count;

	ft_asprintf(&count, "Steps : %d", cmds->step_number);
	if (count)
	{
		mlx_string_put(win->mlx_id, win->self_id, 5, 0, TEXT_COLOR, count);
		ft_memdel((void**)&count);
	}
	if (win->prevmove == PREVMOVE && cmds->step_number != 0)
		mlx_string_put(win->mlx_id, win->self_id, win->width / 2 - 20, 10,
							TEXT_COLOR, "<<<");
	if (show_nextmove(data))
		draw_ui_nextmove(win, cmd);
	return (0);
}
