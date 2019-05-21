/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:29:06 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:37:31 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

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
}

static void		ft_check_option_checker_plus(t_check *handle, int i, int j)
{
	if (handle->option == NULL)
	{
		if (!(handle->option = (char*)malloc(sizeof(char)
						* ft_strlen(handle->argv[1]) - 1)))
			ft_print_error_checker();
		j = 0;
	}
	else
	{
		ft_realloc_checker(handle, ft_strlen(handle->option)
				+ ft_strlen(handle->argv[1]) - 1);
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
		ft_check_option_checker_plus(handle, i, j);
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
