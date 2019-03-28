/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_ope.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 09:14:39 by akremer           #+#    #+#             */
/*   Updated: 2019/03/28 09:36:42 by akremer          ###   ########.fr       */
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
	if (handle->sizea == 0)
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
	ft_realloc_push_swap(handle, "pb\n", 3);
}
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
//	if (handle->sizeb == 0)
//		return ;
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
	ft_realloc_push_swap(handle, "pa\n", 3);
}
