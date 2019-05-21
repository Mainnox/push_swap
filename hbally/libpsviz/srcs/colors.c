/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:02:07 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:03:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"
#include "colors.h"
#include "libft.h"

static int		merge_color(t_color *color)
{
	return ((int)((color->r << 16) + (color->g << 8) + color->b));
}

static float	gradient(int16_t start, int16_t end, int16_t steps)
{
	int16_t		diff;
	double		fdiff;
	double		fsteps;

	diff = ft_abs16(end - start);
	fdiff = (double)diff;
	fsteps = (double)steps;
	return ((start < end ? 1.0f : -1.0f) * (fdiff / fsteps));
}

static void		split_color(t_color *color, int color_int)
{
	color->r = (color_int & 0xFF0000) >> 16;
	color->g = (color_int & 0x00FF00) >> 8;
	color->b = color_int & 0xFF;
}

static void		update_color(t_color *now, t_delta delta, t_delta *compound)
{
	compound->r += delta.r;
	compound->g += delta.g;
	compound->b += delta.b;
	if ((delta.r > 0.001f && (int)compound->r > now->r)
			|| (delta.r < 0.001 && (int)compound->r < now->r))
		now->r = (int)compound->r;
	if ((delta.g > 0.001f && (int)compound->g > now->g)
			|| (delta.g < 0.001 && (int)compound->g < now->g))
		now->g = (int)compound->g;
	if ((delta.b > 0.001f && (int)compound->b > now->b)
			|| (delta.b < 0.001 && (int)compound->b < now->b))
		now->b = (int)compound->b;
}

void			get_color(t_vizlst *node1, t_vizlst *node2, int16_t steps,
								int nextcolor)
{
	t_vizlst		*elem;
	static t_color	now;
	static t_delta	compound;
	t_color			end;
	t_delta			delta;

	if (nextcolor == COLOR_1)
	{
		split_color(&now, START_COLOR);
		compound.r = (double)now.r;
		compound.g = (double)now.g;
		compound.b = (double)now.b;
	}
	split_color(&end, nextcolor);
	delta.r = gradient(now.r, end.r, steps);
	delta.g = gradient(now.g, end.g, steps);
	delta.b = gradient(now.b, end.b, steps);
	elem = node1;
	while (elem != node2)
	{
		elem->color = merge_color(&now);
		update_color(&now, delta, &compound);
		elem = elem->next;
	}
}
