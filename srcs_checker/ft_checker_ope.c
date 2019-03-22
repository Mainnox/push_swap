/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_swap_ope.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 09:14:39 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 14:45:10 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_swap_b_checker(t_check *handle)
{
	int		tmp;

	if (!handle->b[0] && !handle->b[1])
		return ;
	tmp = handle->b[0];
	handle->b[0] = handle->b[1];
	handle->b[1] = tmp;
	handle->nb_ope++;
}

void		ft_rotate_b_checker(t_check *handle)
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
}

void		ft_reverse_rotate_b_checker(t_check *handle)
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
}

void		ft_push_b_checker(t_check *handle)
{
	int i;

	i = handle->sizea;
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
}

void		ft_swap_a_checker(t_check *handle)
{
	int		tmp;

	if (!handle->a[0] || !handle->a[1])
		return ;
	tmp = handle->a[0];
	handle->a[0] = handle->a[1];
	handle->a[1] = tmp;
	handle->nb_ope++;
}

void		ft_rotate_a_checker(t_check *handle)
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
}

void		ft_reverse_rotate_a_checker(t_check *handle)
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
}

void		ft_push_a_checker(t_check *handle)
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
}
