/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_ope_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:16:27 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 14:16:30 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_swap_b_checker(t_check *handle)
{
	int		tmp;

	handle->nb_ope++;
	if (handle->sizeb < 2)
		return ;
	tmp = handle->b[0];
	handle->b[0] = handle->b[1];
	handle->b[1] = tmp;
}

void		ft_rotate_b_checker(t_check *handle)
{
	int start;
	int i;

	i = 0;
	handle->nb_ope++;
	if (handle->sizeb < 2)
		return ;
	start = handle->b[0];
	while (i < handle->sizeb - 1)
	{
		handle->b[i] = handle->b[i + 1];
		i++;
	}
	handle->b[handle->sizeb - 1] = start;
}

void		ft_reverse_rotate_b_checker(t_check *handle)
{
	int end;
	int i;

	i = handle->sizeb - 1;
	handle->nb_ope++;
	if (handle->sizeb < 2)
		return ;
	end = handle->b[i];
	while (i > 0)
	{
		handle->b[i] = handle->b[i - 1];
		i--;
	}
	handle->b[0] = end;
}

void		ft_push_b_checker(t_check *handle)
{
	int i;

	i = handle->sizea;
	handle->nb_ope++;
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
}
