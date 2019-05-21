/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_plus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:52:53 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:23:46 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int							ft_how_many_less(int *tab, int size, long nb)
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

long						ft_find_mid(int *tab, int size, int nbr_ok)
{
	int		i;
	int		less;

	i = 0;
	if (size <= nbr_ok)
		return (21474836470);
	while (i < size)
	{
		less = ft_how_many_less(tab, size, tab[i]);
		if (less == size / 2)
			break ;
		i++;
	}
	return ((long)tab[i]);
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

int							ft_replace_head(int *tab, int size, int ign)
{
	int		i;

	i = 0;
	if (ign == 0)
		ign = 1;
	while (i < size)
	{
		if (ft_how_many_less(tab, size, tab[i]) == ign - 1)
			break ;
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
