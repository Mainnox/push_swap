/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reduc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:14:18 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 16:40:02 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_replace_hack(char *hack, char *replace, char *str)
{
	int		size_to_delete;
	int		start;
	char 	*new;

	size_to_delete = (ft_strlen(replace) * 2) + 2;
	start = ft_strlen(hack) - ft_strlen(str);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(hack)
						- size_to_delete + ft_strlen(replace) + 1))))
		return (-1);
	ft_strncpy(new, hack, start);
	ft_strcat(new, replace);
	str = str + size_to_delete;
	ft_strcat(new, str);
	return (0);
}

void		ft_check_reduction(t_push *handle)
{
	char *str;

	while (42)
	{
		if (str = ft_strstr(handle->hack, "sa\nsb\n")
					|| str = ft_strstr(handle->hack, "sb\nsa\n"))
		{
			ft_replace_hack(handle->hack, "ss", str);
			continue ;
		}
		if (str = ft_strstr(handle->hack, "rra\nrrb\n")
					|| str = ft_strstr(handle->hack, "rrb\nrra\n"))
		{
			ft_replace_hack(handle->hack, "rrr", str);
			continue ;
		}
		if (str = ft_strstr(handle->hack, "ra\nrb\n")
					|| str = ft_strstr(handle->hack, "rb\nra\n"))
		{
			ft_replace_hack(handle->hack, "rr", str);
			continue ;
		}
		break ;
	}
}
