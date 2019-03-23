/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:29:06 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 21:13:00 by akremer          ###   ########.fr       */
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
	if (handle->sizeb == 0)
		return (1);
	return (0);
}

static void		ft_realloc_checker(t_check *handle, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * n)))
		ft_print_error_checker();
	ft_strcpy(str, handle->option);
	free(handle->option);
	handle->option = str;
}

static void		ft_reorder_argv(t_check *handle)
{
	int i;

	i = 0;
	while (i < handle->size)
	{
		handle->argv[i] = ft_strdup(handle->argv[i + 1]);
		if (handle->argv[i] == NULL)
			ft_print_error_checker();
		i++;
	}
	handle->size--;
//	free(handle->argv[i + 1]);
}

static int		ft_check_option_checker(t_check *handle)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	if (handle->argv[1][0] == '-' && ft_isalpha(handle->argv[1][1]))
	{
		if (handle->option == NULL)
		{
			if (!(handle->option = (char*)malloc(sizeof(char) * ft_strlen(handle->argv[1]) - 1)))
				ft_print_error_checker();
			j = 0;
		}
		else
		{
			ft_realloc_checker(handle, ft_strlen(handle->option) + ft_strlen(handle->argv[1]) - 1);
			j = ft_strlen(handle->option);
		}
		while (handle->argv[1][i])
		{
			handle->option[j] = handle->argv[1][i];
			j++;
			i++;
		}
		handle->option[j] = '\0';
		ft_reorder_argv(handle);
		return (1);
	}
	return (0);
}

void			ft_fill_argv_checker(t_check *handle)
{
	int i;

	i = 0;
	while (ft_check_option_checker(handle) == 1)
		continue ;
	handle->sizea = handle->size;
	ft_check_argv_checker(handle);
	ft_check_a_checker(handle);
}
