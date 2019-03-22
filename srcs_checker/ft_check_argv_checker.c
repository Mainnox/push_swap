/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:29:06 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 12:45:02 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void			ft_check_argv_checker(t_check *handle)
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
				ft_print_error_checker();
			}
			j++;
		}
		handle->a[i - 1] = ft_atoi_checker(handle->argv[i]);
		i++;
	}
}

static void			ft_check_a_checker(t_check *handle)
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
				ft_print_error_checker();
			j++;
		}
		i++;
	}
}

int				ft_is_sort_checker(t_check *handle)
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

void			ft_fill_argv_checker(t_check *handle)
{
	ft_check_argv_checker(handle);
	ft_check_a_checker(handle);
}
