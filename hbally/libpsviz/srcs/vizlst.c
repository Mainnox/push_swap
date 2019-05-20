/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:00:01 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:00:07 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "libpsviz.h"
#include "libft.h"
#include "colors.h"

void		vizlst_add(t_data *data, t_vizstack *stack, int n)
{
	t_vizlst	*new;

	if (!(new = (t_vizlst*)ft_memalloc(sizeof(t_vizlst))))
		exit_window(data, data->win, MALLOC_ERROR);
	new->n = n;
	new->next = NULL;
	if (!stack->start)
		stack->start = new;
	if (stack->end)
		stack->end->next = new;
	stack->end = new;
	stack->len++;
}
