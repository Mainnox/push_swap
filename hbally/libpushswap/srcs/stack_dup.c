/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:10:41 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:10:45 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "libft.h"

void				stack_dup(t_data *data, t_stack *stack, size_t len)
{
	t_intlst		*node;
	size_t			i;

	i = 0;
	ft_bzero(&(data->c), sizeof(t_stack));
	node = stack->start;
	while (node && i < len)
	{
		lst_add(data, &(data->c), node->n);
		node = node->next;
		i++;
	}
}
