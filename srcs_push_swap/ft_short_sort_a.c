/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:25:35 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 11:56:23 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int			ft_find_mid_under_5_a(int *tab, int size)
{
	int		i;
	int		less;

	i = 0;
	while (i < size)
	{
		less = ft_how_many_less(tab, size, tab[i]);
		if (less == size / 2)
			break ;
		i++;
	}
	return (tab[i]);
}

static void			ft_more_than_3_a(t_push *handle,
		int size, int odd, int mid)
{
	while (handle->sizea > size + odd)
	{
		if (handle->a[0] < mid)
			ft_push_a(handle);
		else
			ft_rotate_a(handle);
	}
}

void				ft_sort_under_5_a(t_push *handle)
{
	int		mid;
	int		odd;
	int		size;

	size = handle->sizea / 2;
	odd = (handle->sizea % 2 == 0) ? 0 : 1;
	mid = ft_find_mid_under_5_a(handle->a, handle->sizea);
	if (handle->sizea >= 4)
		ft_more_than_3_a(handle, size, odd, mid);
	if (!ft_is_sort(handle->a, handle->sizea))
		ft_algo_insert_a(handle);
	if (handle->b[0] < handle->b[1])
		ft_swap_b(handle);
	while (handle->sizeb)
		ft_push_b(handle);
}
