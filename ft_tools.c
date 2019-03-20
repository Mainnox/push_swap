/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:56:18 by akremer           #+#    #+#             */
/*   Updated: 2019/03/20 14:27:52 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_realloc_push_swap(t_push *handle, char *ope, size_t k)
{
	char	*hack2;
	size_t	size;

	if (handle->hack)
		size = ft_strlen(handle->hack) + k;
	else
		size = k + 1;
	if (!(hack2 = (char*)malloc(sizeof(char) * size)))
		return (0);
	if (handle->hack)
		ft_strcpy(hack2, handle->hack);
	handle->hack = ft_strjoin(hack2, ope);
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
			i++;
		}
		if (result > 2147483647 || result < -2147483648)
			ft_print_error();
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
