/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:28:48 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 17:47:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void					ft_split_a(t_push *handle)
{
	int		i;
	int		size;
	int		j;

	i = 0;
	size = handle->sizea - handle->ign;
	handle->mid = ft_find_mid(handle->a, handle->sizea - handle->ign,
			handle->nbr_ok);
	j = ft_how_many_less(handle->a, handle->sizea, handle->mid);
	while (i < size)
	{
		if (handle->a[0] < handle->mid)
		{
			j--;
			ft_push_a(handle);
		}
		else
		{
			ft_rotate_a(handle);
		}
		i++;
		if (j <= 0)
			break ;
	}
}

static int					ft_split_b_while(t_push *handle, int size,
		int mid, int j)
{
	int		i;
	int		progres;

	progres = 0;
	i = -1;
	while (++i < size)
	{
		if (handle->b[0] == handle->low)
		{
			ft_put_b_on_a(handle, 1);
			handle->low = ft_find_low(handle);
			continue ;
		}
		if (handle->b[0] > mid)
		{
			progres++;
			ft_push_b(handle);
			j--;
		}
		else
			ft_rotate_b(handle);
		if (j <= 0)
			break ;
	}
	return (progres);
}

static void					ft_split_b(t_push *handle)
{
	int		mid;
	int		size;
	int		progres;
	int		j;

	size = handle->sizeb;
	mid = ft_find_mid(handle->b, handle->sizeb, handle->nbr_ok);
	j = ft_how_many_less(handle->b, handle->sizeb, mid);
	progres = ft_split_b_while(handle, size, mid, j);
	if (progres != 0)
		ft_add_progress(handle, progres);
	if (handle->sizeb > handle->nbr_ok)
	{
		handle->mid = ft_find_bigger(handle->b, handle->sizeb) + 1;
		ft_split_b(handle);
	}
}

static void					ft_quick_sort_end(t_push *handle)
{
	if (handle->tour != 0)
		ft_wich_path(handle, ft_replace_head(handle->a,
				handle->sizea, handle->ign), -1);
	if (handle->sizeb > handle->nbr_ok)
		ft_split_b(handle);
	if (handle->sizeb <= handle->nbr_ok && handle->sizeb)
		ft_sort_under_5(handle);
	if (handle->sizeb)
		ft_put_b_on_a(handle, handle->sizeb);
}

void						ft_quick_sort_1(t_push *handle)
{
	if (!ft_find_this(handle->a, handle->sizea - handle->ign, handle->low)
			&& !ft_find_this(handle->b, handle->sizeb, handle->low))
		handle->low = ft_find_low(handle);
	if (handle->sizea - handle->ign > 0 && handle->progres[0] <= 0)
		ft_split_a(handle);
	else
	{
		while (handle->progres[handle->size_progres - 2])
		{
			ft_push_a(handle);
			handle->progres[handle->size_progres - 2]--;
		}
		ft_realloc_progress(handle, 0);
	}
	ft_quick_sort_end(handle);
	if (!ft_is_sort(handle->a, handle->sizea) && !handle->sizeb)
	{
		handle->tour++;
		ft_quick_sort_1(handle);
	}
}
