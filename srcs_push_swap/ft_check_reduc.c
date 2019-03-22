/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reduc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:14:18 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 18:49:49 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static char *ft_where(char *hack, char *replace)
{
	if (ft_strcmp(replace, "ss\n") == 0)
	{
		if (ft_strstr(hack, "sa\nsb\n"))
			return (ft_strstr(hack, "sa\nsb\n"));
		if (ft_strstr(hack, "sb\nsa\n"))
			return (ft_strstr(hack, "sb\nsa\n"));
	}
	if (ft_strcmp(replace, "rr\n") == 0)
	{
		if (ft_strstr(hack, "ra\nrb\n"))
			return (ft_strstr(hack, "ra\nrb\n"));
		if (ft_strstr(hack, "rb\nra\n"))
			return (ft_strstr(hack, "rb\nra\n"));
	}
	if (ft_strcmp(replace, "rrr\n") == 0)
	{
		if (ft_strstr(hack, "rra\nrrb\n"))
			return (ft_strstr(hack, "rra\nrrb\n"));
		if (ft_strstr(hack, "rrb\nrra\n"))
			return (ft_strstr(hack, "rrb\nrra\n"));
	}
	return (NULL);
}

static int	ft_replace_hack(t_push *handle, char *replace)
{
	int		size_to_delete;
	int		start;
	char 	*new;
	char	*str;

	str = ft_where(handle->hack, replace);
	size_to_delete = (ft_strlen(replace) * 2);
	start = ft_strlen(handle->hack) - ft_strlen(str);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(handle->hack)
						- size_to_delete + ft_strlen(replace) + 1))))
		return (-1);
	ft_strncpy(new, handle->hack, start);
	ft_strcat(new, replace);
	str = str + size_to_delete;
	ft_strcat(new, str);
	handle->hack = new;
	return (0);
}

void		ft_check_reduc(t_push *handle)
{
	while (42)
	{
		if (ft_strstr(handle->hack, "sa\nsb\n")
					|| ft_strstr(handle->hack, "sb\nsa\n"))
		{
			ft_replace_hack(handle, "ss\n");
			continue ;
		}
		if (ft_strstr(handle->hack, "rra\nrrb\n")
					|| ft_strstr(handle->hack, "rrb\nrra\n"))
		{
			ft_replace_hack(handle, "rrr\n");
			continue ;
		}
		if (ft_strstr(handle->hack, "ra\nrb\n")
					|| ft_strstr(handle->hack, "rb\nra\n"))
		{
			ft_replace_hack(handle, "rr\n");
			continue ;
		}
		break ;
	}
}
