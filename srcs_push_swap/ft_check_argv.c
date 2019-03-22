/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:07:23 by akremer           #+#    #+#             */
/*   Updated: 2019/03/20 12:44:39 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void			ft_check_argv(t_push *handle)
{
	int i;
	int j;

	i = 1;
	while (i <= handle->size)
	{
		j = 0;
		while (handle->argv[i][j])
		{
			if (ft_isdigit(handle->argv[i][j]) == 0)
			{
				if (handle->argv[i][j] == '-' && ft_isdigit(handle->argv[i][j + 1]) == 1)
				{
					j++;
					continue ;
				}
				ft_print_error();
			}
			j++;
		}
		handle->a[i - 1] = ft_atoi_push_swap(handle->argv[i]);
		i++;
	}
}

static void			ft_check_a(t_push *handle)
{
	int i;
	int j;

	i = 0;
	while (i < handle->size - 1)
	{
		j = i + 1;
		while (j < handle->size)
		{
			if (handle->a[i] == handle->a[j])
				ft_print_error();
			j++;
		}
		i++;
	}
}

int				ft_is_sort(t_push *handle)
{
	int i;
	int j;

	i = 0;
	if (handle->size == 1)
		return (1);
	while (i < handle->size - 1)
	{
		j = i + 1;
		while (j < handle->size)
		{
			if (handle->a[i] > handle->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_fill_argv(t_push *handle)
{
	ft_check_argv(handle);
	ft_check_a(handle);
}
