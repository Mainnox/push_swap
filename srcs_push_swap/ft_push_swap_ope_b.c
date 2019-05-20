/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_ope_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:09:27 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 11:09:44 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_swap_b(t_push *handle)
{
	int		tmp;

	if (handle->sizeb < 2)
		return ;
	tmp = handle->b[0];
	handle->b[0] = handle->b[1];
	handle->b[1] = tmp;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "sb\n", 3);
}

void		ft_rotate_b(t_push *handle)
{
	int start;
	int i;

	i = 0;
	if (handle->sizeb < 2)
		return ;
	start = handle->b[0];
	while (i < handle->sizeb - 1)
	{
		handle->b[i] = handle->b[i + 1];
		i++;
	}
	handle->b[handle->sizeb - 1] = start;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "rb\n", 3);
}

void		ft_reverse_rotate_b(t_push *handle)
{
	int end;
	int i;

	i = handle->sizeb - 1;
	if (handle->sizeb < 2)
		return ;
	end = handle->b[i];
	while (i > 0)
	{
		handle->b[i] = handle->b[i - 1];
		i--;
	}
	handle->b[0] = end;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "rrb\n", 4);
}

void		ft_push_b(t_push *handle)
{
	int i;

	i = handle->sizea;
	if (handle->sizeb == 0)
		return ;
	while (i > 0)
	{
		handle->a[i] = handle->a[i - 1];
		i--;
	}
	handle->a[0] = handle->b[0];
	i = 0;
	while (i < handle->sizeb - 1)
	{
		handle->b[i] = handle->b[i + 1];
		i++;
	}
	handle->b[i] = 0;
	handle->sizea++;
	handle->sizeb--;
	handle->nb_ope++;
	ft_realloc_push_swap(handle, "pa\n", 3);
}
