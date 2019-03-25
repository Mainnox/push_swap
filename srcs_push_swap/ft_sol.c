/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 07:51:24 by akremer           #+#    #+#             */
/*   Updated: 2019/03/25 08:45:31 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_fill_sol(t_push *handle, t_sol **sol)
{
	t_sol	*tmp;

	tmp = *sol;
	while (tmp->next)
		tmp = tmp->next;
	tmp->sol = ft_strdup(handle->hack);
	tmp->nb_ope = handle->nb_ope;
	*sol = tmp;
}

static char	*ft_find_the_best(t_sol **sol, int ope_min)
{
	t_sol*tmp;

	tmp = *sol;
	while (tmp->next)
	{
		if (tmp->nb_ope == ope_min)
			return (tmp->sol);
		tmp = tmp->next;
	}
	return (tmp->sol);
}

char		*ft_print_the_best(t_sol **sol)
{
	int		ope_min;
	t_sol	*tmp;

	tmp = *sol;
	ope_min = tmp->nb_ope;
	while (tmp)
	{
		if (tmp->nb_ope < ope_min)
			ope_min = tmp->nb_ope;
		tmp = tmp->next;
	}
	return (ft_find_the_best(sol, ope_min));
}
