/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:56:18 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:04:44 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_realloc_push_swap(t_push *handle, char *ope, size_t k)
{
	char *hack2;

	hack2 = ft_strjoin(handle->hack, ope);
	if (handle->hack)
		free(handle->hack);
	handle->hack = hack2;
	return (1);
}

int			ft_atoi_push_swap(char *str)
{
	long i;
	long nega;
	long result;

	nega = 1;
	result = 0;
	i = 0;
	if (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				nega = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - 48;
			if ((result > 2147483648 && nega == -1)
					|| (result > 2147483647 && nega == 1))
				ft_print_error();
			i++;
		}
	}
	return (result * nega);
}

void		ft_print_tab(int *tab, size_t size, char *name)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		ft_printf("%s[%d] = %d\n", name, i, tab[i]);
		i++;
	}
}
