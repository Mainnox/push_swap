/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:56:51 by hbally            #+#    #+#             */
/*   Updated: 2019/02/07 22:41:15 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"

static void		get_barheight(t_win *win)
{
	if ((MAX_WIN_HEIGHT - win->top_pad) / win->max_len <= 1)
		win->bar_height = 1;
	else
	{
		win->bar_height = (win->height - win->top_pad) / win->max_len;
		if (win->bar_height > 30)
			win->bar_height = 30;
	}
}

static void		get_barwidth(t_win *win)
{
	win->bar_maxwidth = (win->width / 2) - (2 * win->side_pad);
	if ((win->bar_step = (win->bar_maxwidth - MINWIDTH) / win->max_len) <= 0)
		win->bar_step = 1;
}

static void		add_anchors(t_win *win)
{
	if (MINWIDTH + win->max_len + 2 * win->side_pad > win->width / 2)
	{
		win->mini = 1;
		while (win->width / 2
					> (MINWIDTH + win->max_len / 2 + 2 * win->side_pad))
			win->width--;
		win->a_anchor.x = MINI_PADDING;
		win->b_anchor.x = win->width - MINI_PADDING;
	}
	else
	{
		win->a_anchor.x = win->width / 4;
		win->b_anchor.x = win->width / 4 + win->width / 2;
	}
	win->a_anchor.y = win->height - 1;
	win->b_anchor.y = win->height - 1;
}

static void		get_startvalues(t_data *data, t_win *win)
{
	win->max_len = data->a.len;
	win->width = START_WIN_WIDTH;
	win->height = START_WIN_HEIGHT;
	if (win->max_len >= 100)
	{
		win->width += 200;
		win->height += 300;
	}
	win->top_pad = TOP_PADDING;
	win->side_pad = SIDE_PADDING;
	win->bar_minwidth = MINWIDTH;
	get_barheight(win);
	get_barwidth(win);
}

void			get_window_size(t_data *data, t_win *win)
{
	get_startvalues(data, win);
	while ((win->max_len * win->bar_height) > (win->height - win->top_pad)
				&& win->height < MAX_WIN_HEIGHT)
	{
		win->height++;
		get_barheight(win);
	}
	while (win->height - win->top_pad > win->bar_height * win->max_len)
		win->height--;
	while ((win->bar_maxwidth + 2 * win->side_pad > win->width / 2
				|| MINWIDTH + win->max_len + 2 * win->side_pad > win->width / 2)
				&& win->width < MAX_WIN_WIDTH)
	{
		win->width++;
		get_barwidth(win);
	}
	add_anchors(win);
}
