/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:34:49 by hbally            #+#    #+#             */
/*   Updated: 2018/12/16 00:13:51 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpsviz.h"

static void		img_update(t_win *win, int color, int16_t x, int16_t y)
{
	if (x < win->width && y < win->height && x > 0 && y > 0)
		ft_memmove(&(win->img.data[(y * win->img.line_size) + (x * 4)]),
							&color, sizeof(int));
}

static void		draw_line_low(t_win *win, int color, t_vect p1, t_vect p2)
{
	int16_t		dx;
	int16_t		dy;
	int16_t		increment;
	int16_t		error;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	increment = dy > 0 ? 1 : -1;
	dy *= dy > 0 ? 2 : -2;
	error = dy - dx;
	dx *= 2;
	while (p1.x <= p2.x)
	{
		img_update(win, color, p1.x, p1.y);
		if (error > 0)
		{
			p1.y += increment;
			error -= dx;
		}
		error += dy;
		p1.x++;
	}
}

static void		draw_line_steep(t_win *win, int color, t_vect p1, t_vect p2)
{
	int16_t		dx;
	int16_t		dy;
	int16_t		error;
	int16_t		increment;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	increment = dx > 0 ? 1 : -1;
	dx *= dx > 0 ? 2 : -2;
	error = dx - dy;
	dy *= 2;
	while (p1.y <= p2.y)
	{
		img_update(win, color, p1.x, p1.y);
		if (error > 0)
		{
			p1.x += increment;
			error -= dy;
		}
		error += dx;
		p1.y++;
	}
}

void			drawline(t_win *win, int color, t_vect p1, t_vect p2)
{
	if (ft_abs16(p2.y - p1.y) < ft_abs16(p2.x - p1.x))
	{
		if (p2.x > p1.x)
			draw_line_low(win, color, p1, p2);
		else
			draw_line_low(win, color, p2, p1);
	}
	else
	{
		if (p2.y > p1.y)
			draw_line_steep(win, color, p1, p2);
		else
			draw_line_steep(win, color, p2, p1);
	}
}
