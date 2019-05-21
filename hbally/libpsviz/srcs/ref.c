/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:56:21 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:03:02 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"
#include "colors.h"

static void		apply_colors(t_vizstack *ref, t_win *win)
{
	get_color(ref->start, ref->mid, win->max_len / 2, COLOR_1);
	get_color(ref->mid, NULL, win->max_len / 2, END_COLOR);
}

static void		apply_attributes(t_win *win, t_vizstack *ref)
{
	t_vizlst	*node;
	size_t		i;

	node = ref->start;
	i = 0;
	while (node)
	{
		node->width = win->bar_minwidth + i * win->bar_step;
		node->height = win->bar_height;
		node = node->next;
		i++;
	}
}

static void		find_quartiles(t_vizstack *ref)
{
	t_vizlst	*node;

	ref->mid = mid(ref->start);
	node = ref->mid->next;
	ref->mid->next = NULL;
	ref->q1 = mid(ref->start);
	ref->mid->next = node;
	ref->q3 = mid(ref->mid);
}

static void		create_ref(t_data *data)
{
	t_intlst	*node;

	node = data->a.start;
	while (node)
	{
		vizlst_add(data, &(data->win->ref), node->n);
		node = node->next;
	}
	data->win->ref.start = sort(data->win->ref.start);
	find_quartiles(&(data->win->ref));
}

void			get_ref(t_data *data)
{
	create_ref(data);
	get_window_size(data, data->win);
	apply_attributes(data->win, &(data->win->ref));
	apply_colors(&(data->win->ref), data->win);
}
