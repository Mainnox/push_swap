/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:04:39 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 15:08:49 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int				ft_big_while_insert_b(t_push *handle, int max)
{
	int		i;
	int		j;
	int		rotate;

	rotate = 0;
	i = 2;
	j = 0;
	while (i <= handle->sizeb)
	{
		if (!ft_is_nsort(handle->b, i))
		{
			if (handle->b[0] == max)
			{
				ft_push_b(handle);
				max = ft_find_n_bigger(handle->b, handle->sizeb, max);
				if (i != 2)
					i--;
				rotate++;
				continue ;
			}
			if (handle->b[0] == handle->low)
			{
				ft_put_b_on_a(handle, 1);
				handle->low = ft_find_low(handle);
				if (i != 2)
					i--;
				continue ;
			}
			if (handle->b[0] > handle->b[1])
				ft_swap_b(handle);
			if (!ft_is_nsort(handle->b, i))
			{
				ft_rotate_b(handle);
				j++;
				i--;
				continue ;
			}
			i += j;
			while (j > 0)
			{
				ft_reverse_rotate_b(handle);
				j--;
			}
		}
		if (ft_is_sort(handle->b, handle->sizeb))
			break ;
		if (i < handle->sizeb)
			ft_reverse_rotate_b(handle);
		i++;
	}
	return (rotate);
}

void				ft_algo_insert_b(t_push *handle)
{
	int		i;
	int		j;
	int		max;
	int		rotate;

	max = ft_find_bigger(handle->b, handle->sizeb);
	i = 2;
	j = 0;
	rotate = ft_big_while_insert_b(handle, max);
	while (handle->sizeb)
		ft_put_b_on_a(handle, 1);
	handle->ign += rotate;
	while (rotate)
	{
		ft_rotate_a(handle);
		rotate--;
	}
}
