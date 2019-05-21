/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lastmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:44:30 by hbally            #+#    #+#             */
/*   Updated: 2019/02/25 15:56:13 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpsviz.h"
#include "colors.h"

static void		move(t_vect *start, t_vect *end, int delta)
{
	if (start->x == end->x)
	{
		start->x += delta;
		end->x += delta;
	}
	else
	{
		start->y += delta;
		end->y += delta;
	}
}

static void		draw_arrowend(t_data *data, int color, t_vect start, t_vect end)
{
	t_vect		target;

	if (start.x == end.x)
	{
		target.y = start.y < end.y ? end.y - 10 : end.y + 10;
		target.x = end.x + 5;
		while (target.x != end.x - 5)
		{
			drawline(data->win, color, end, target);
			target.x--;
		}
	}
	else
	{
		target.x = end.x > start.x ? end.x - 10 : end.x + 10;
		target.y = end.y;
		while (end.x >= start.x ? end.x >= target.x : end.x <= target.x)
		{
			drawline(data->win, color, end, target);
			target.y -= 1;
			end.y -= 1;
			end.x += end.x >= start.x ? -1 : 1;
		}
	}
}

static void		draw_arrow(t_data *data, t_vect start, t_vect end)
{
	int			color;

	color = MOVE_COLOR;
	draw_arrowend(data, color, start, end);
	drawline(data->win, color, start, end);
	move(&start, &end, 1);
	drawline(data->win, color, start, end);
	move(&start, &end, -2);
}

static void		get_anchors(t_data *data, t_win *win)
{
	win->a_top.x = win->a_anchor.x;
	win->a_top.y = win->a_anchor.y - data->a.len * win->bar_height;
	win->b_top.x = win->b_anchor.x;
	win->b_top.y = win->b_anchor.y - data->b.len * win->bar_height;
}

int				add_lastmove(t_data *data, t_win *win, char *cmd)
{
	get_anchors(data, win);
	if (!ft_strcmp(cmd, "pb"))
		draw_arrow(data, win->a_top, win->b_top);
	if (!ft_strcmp(cmd, "pa"))
		draw_arrow(data, win->b_top, win->a_top);
	if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rr"))
		draw_arrow(data, win->a_anchor, win->a_top);
	if (!ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr"))
		draw_arrow(data, win->b_anchor, win->b_top);
	if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrr"))
		draw_arrow(data, win->a_top, win->a_anchor);
	if (!ft_strcmp(cmd, "rrb") || !ft_strcmp(cmd, "rrr"))
		draw_arrow(data, win->b_top, win->b_anchor);
	return (0);
}
