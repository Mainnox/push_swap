/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_checker_plus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:07:22 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:37:36 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void			ft_check_argv_checker(t_check *handle)
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
				if (handle->argv[i][j] == '-'
						&& ft_isdigit(handle->argv[i][j + 1]) == 1)
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

void			ft_check_a_checker(t_check *handle)
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
	if (handle->sizeb == 0)
		return (1);
	return (0);
}
