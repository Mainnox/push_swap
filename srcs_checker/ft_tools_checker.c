/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:56:18 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 17:08:20 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int			ft_atoi_checker(char *str)
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
			i++;
			if ((result > 2147483647 && nega == 1)
					|| (result > 2147483648 && nega == -1))
				ft_print_error_checker();
		}
	}
	return (result * nega);
}

void		ft_print_tab_checker(int *tab, size_t size, char *name)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		ft_printf("%s[%d] = %d\n", name, i, tab[i]);
		i++;
	}
}
