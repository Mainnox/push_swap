/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_ope.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 09:14:39 by akremer           #+#    #+#             */
/*   Updated: 2019/03/20 09:48:10 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_swap(t_push *handle)
{
	int		tmp;

	if (!handle->a[0] || !handle->a[1])
		return ;
	tmp = handle->a[0];
	handle->a[0] = handle->a[1];
	handle->a[1] = tmp;
}

void		ft_rotate(t_push *handle)
{
	int start;
	int i;

	i = 0;
	if (handle->size < 2)
		return ;
	start = handle->a[0];
	while (i < handle->size - 1)
	{
		handle->a[i] = handle->a[i + 1];
		i++;
	}
	handle->a[handle->size - 1] = start;
}

void		ft_reverse_rotate(t_push *handle)
{
	int end;
	int i;

	i = handle->size - 1;
	if (handle->size < 2)
		return ;
	end = handle->a[i];
	while (i > 0)
	{
		handle->a[i] = handle->a[i - 1];
		i--;
	}
	handle->a[0] = end;
}

void		ft_push(t_push *handle)
{
	int i;

	i = handle->size - 1;
	while (i > 0)
	{
		handle->b[i] = handle->b[i - 1];
		i--;
	}
	handle->b[0] = handle->a[0];
	i = 0;
	while (i < handle->size - 1)
	{
		handle->a[i] = handle->a[i + 1];
		i++;
	}
	handle->a[i] = 0;
}
