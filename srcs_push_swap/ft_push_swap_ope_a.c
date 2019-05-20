/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_ope_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:10:16 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 11:10:35 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_swap_a(t_push *handle)
{
	int		tmp;

	if (handle->sizea < 2)
		return ;
	tmp = handle->a[0];
	handle->a[0] = handle->a[1];
	handle->a[1] = tmp;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "sa\n", 3);
}

void		ft_rotate_a(t_push *handle)
{
	int start;
	int i;

	i = 0;
	if (handle->sizea < 2)
		return ;
	start = handle->a[0];
	while (i < handle->sizea - 1)
	{
		handle->a[i] = handle->a[i + 1];
		i++;
	}
	handle->a[handle->sizea - 1] = start;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "ra\n", 3);
}

void		ft_reverse_rotate_a(t_push *handle)
{
	int end;
	int i;

	i = handle->sizea - 1;
	if (handle->sizea < 2)
		return ;
	end = handle->a[i];
	while (i > 0)
	{
		handle->a[i] = handle->a[i - 1];
		i--;
	}
	handle->a[0] = end;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "rra\n", 4);
}

void		ft_push_a(t_push *handle)
{
	int i;

	i = handle->sizeb;
	while (i > 0)
	{
		handle->b[i] = handle->b[i - 1];
		i--;
	}
	handle->b[0] = handle->a[0];
	i = 0;
	while (i < handle->sizea - 1)
	{
		handle->a[i] = handle->a[i + 1];
		i++;
	}
	handle->a[i] = 0;
	handle->sizea--;
	handle->sizeb++;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "pb\n", 3);
}
