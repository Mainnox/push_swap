/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:38:19 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:00:50 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"
#include "colors.h"

static void			draw_bar(t_data *data, t_vect anchor, t_vizlst *ref,
								int color)
{
	int16_t			i;
	t_vect			p1;
	t_vect			p2;

	i = 0;
	while (i < ref->height)
	{
		p1.y = anchor.y - i;
		p1.x = anchor.x;
		p2.y = anchor.y - i;
		if (!data->win->mini || anchor.x < data->win->width / 2)
		{
			p2.x = anchor.x + ref->width / 2;
			drawline(data->win, color, p1, p2);
		}
		if (!data->win->mini || anchor.x > data->win->width / 2)
		{
			p2.x = anchor.x - ref->width / 2;
			drawline(data->win, color, p1, p2);
		}
		i++;
	}
}

static t_vizlst		*find_startpoint(t_vizstack *stack, int n)
{
	if (n < stack->q1->n)
		return (stack->start);
	else if (n < stack->mid->n)
		return (stack->q1);
	else if (n < stack->q3->n)
		return (stack->mid);
	else
		return (stack->q3);
}

void				add_stack(t_data *data, t_vect anchor, t_stack *stack,
									int swap)
{
	t_intlst		*elem;
	t_vizlst		*ref;

	elem = stack->end;
	while (elem)
	{
		ref = find_startpoint(&(data->win->ref), elem->n);
		while (ref && ref->n != elem->n)
			ref = ref->next;
		if (swap && (elem->prev == NULL
						|| (elem->prev && elem->prev->prev == NULL)))
			draw_bar(data, anchor, ref, MOVE_COLOR);
		else
			draw_bar(data, anchor, ref, ref->color);
		anchor.y -= ref->height;
		elem = elem->prev;
	}
}
