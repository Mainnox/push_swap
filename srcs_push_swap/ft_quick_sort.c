/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:28:48 by akremer           #+#    #+#             */
/*   Updated: 2019/05/19 18:37:24 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int					ft_how_many_less(int *tab, int size, int nb)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		if (tab[i] < nb)
			ret++;
		i++;
	}
	return (ret);
}

int							ft_find_mid(int *tab, int size, int nbr_ok)
{
	int		i;
	int		less;

	i = 0;
	if (size <= nbr_ok)
		return (2147483647);
	while (i < size)
	{
		less = ft_how_many_less(tab, size, tab[i]);
		if (less == size / 2)
			break ;
		i++;
	}
	return (tab[i]);
}

static void					ft_split_a(t_push *handle)
{
	int		mid;
	int		i;
	int		size;
	int		j;

	i = 0;
	size = handle->sizea - handle->ign;
	handle->mid = ft_find_mid(handle->a, handle->sizea - handle->ign, handle->nbr_ok);
	mid = handle->mid;
	j = ft_how_many_less(handle->a, handle->sizea, mid);
	while (i < size)
	{
		if (handle->a[0] < mid)
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

void						ft_put_b_on_a(t_push *handle, int how_many)
{
	int		i;

	i = 0;
	while (i < how_many)
	{
		ft_push_b(handle);
		ft_rotate_a(handle);
		i++;
	}	
	handle->ign += i;
}

static void					ft_split_b(t_push *handle)
{
	int		mid;
	int		i;
	int		size;
	int		j;
	int		progres;

	progres = 0;
	size = handle->sizeb;
	i = 0;
	mid = ft_find_mid(handle->b, handle->sizeb, handle->nbr_ok);
	j = ft_how_many_less(handle->b, handle->sizeb, mid);
	while (i < size)
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
		i++;
	}
	if (progres != 0)
		ft_add_progress(handle, progres);
	if (handle->sizeb > handle->nbr_ok)
	{
		handle->mid = ft_find_bigger(handle->b, handle->sizeb) + 1;
		ft_split_b(handle);
	}
}


static int					ft_replace_head(int *tab, int size, int ign)
{
	int		i;

	i = 0;
	if (ign == 0)
		ign = 1;
	while (i < size)
	{
		if (ft_how_many_less(tab, size, tab[i]) == ign - 1)
			break;
		i++;
	}
	return (i);
}

int							ft_find_low(t_push *handle)
{
	int		low;
	int		i;

	i = 0;
	low = handle->a[0];
	while (i < handle->sizea - handle->ign)
	{
		if (low > handle->a[i] && handle->a[i] > handle->low)
			low = handle->a[i];
		i++;
	}
	i = 0;
	while (i < handle->sizeb)
	{
		if (low > handle->b[i] && handle->b[i] > handle->low)
			low = handle->b[i];
		i++;
	}
	return (low);
}

void						ft_quick_sort_1(t_push *handle)
{
	int		tmp;

	tmp = 0;
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
	if (handle->tour != 0)
		ft_wich_path(handle, ft_replace_head(handle->a, handle->sizea, handle->ign)
				, &ft_reverse_rotate_a, &ft_rotate_a, -1);
	if (handle->sizeb > handle->nbr_ok)
		ft_split_b(handle);
	if (handle->sizeb <= handle->nbr_ok && handle->sizeb)
		ft_sort_under_5(handle);
	if (handle->sizeb)
		ft_put_b_on_a(handle, handle->sizeb);
	if (!ft_is_sort(handle->a, handle->sizea) && !handle->sizeb)
	{
		handle->tour++;
		ft_quick_sort_1(handle);
	}
}
