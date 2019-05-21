/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_ope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:59:11 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 14:18:57 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_swap_a_checker(t_check *handle)
{
	int		tmp;

	handle->nb_ope++;
	if (handle->sizea < 2)
		return ;
	tmp = handle->a[0];
	handle->a[0] = handle->a[1];
	handle->a[1] = tmp;
}

void		ft_rotate_a_checker(t_check *handle)
{
	int start;
	int i;

	i = 0;
	handle->nb_ope++;
	if (handle->sizea < 2)
		return ;
	start = handle->a[0];
	while (i < handle->sizea - 1)
	{
		handle->a[i] = handle->a[i + 1];
		i++;
	}
	handle->a[handle->sizea - 1] = start;
}

void		ft_reverse_rotate_a_checker(t_check *handle)
{
	int end;
	int i;

	i = handle->sizea - 1;
	handle->nb_ope++;
	if (handle->sizea < 2)
		return ;
	end = handle->a[i];
	while (i > 0)
	{
		handle->a[i] = handle->a[i - 1];
		i--;
	}
	handle->a[0] = end;
}

void		ft_push_a_checker(t_check *handle)
{
	int i;

	i = handle->sizeb;
	handle->nb_ope++;
	if (handle->sizea == 0)
		return ;
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
}
