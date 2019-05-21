/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:56:44 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 17:25:23 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int			ft_find_mid_under_5(int *tab, int size)
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

static int			ft_more_than_3(t_push *handle, int size, int odd, int mid)
{
	int		check;

	check = 0;
	while (handle->sizeb > size + odd)
	{
		if (handle->b[0] < mid)
		{
			ft_push_b(handle);
			check++;
		}
		else
			ft_rotate_b(handle);
	}
	return (check);
}

void				ft_sort_under_5(t_push *handle)
{
	int		mid;
	int		check;
	int		odd;
	int		size;

	size = handle->sizeb / 2;
	odd = (handle->sizeb % 2 == 0) ? 0 : 1;
	mid = ft_find_mid_under_5(handle->b, handle->sizeb);
	check = 0;
	if (handle->sizeb >= 4)
		check = ft_more_than_3(handle, size, odd, mid);
	if (check)
	{
		if (handle->a[0] > handle->a[1])
			ft_swap_a(handle);
		while (check)
		{
			ft_rotate_a(handle);
			handle->ign++;
			check--;
		}
	}
	if (!ft_is_sort(handle->b, handle->sizeb))
		ft_algo_insert_b(handle);
}
