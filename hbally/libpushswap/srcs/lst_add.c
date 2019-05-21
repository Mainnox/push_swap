/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:22:21 by hbally            #+#    #+#             */
/*   Updated: 2019/02/01 13:57:57 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"

t_intlst		*lst_add(t_data *data, t_stack *stack, int n)
{
	t_intlst	*new;

	if (!(new = (t_intlst*)ft_memalloc(sizeof(t_intlst))))
		clean_exit(MALLOC_ERROR, data);
	new->n = n;
	new->next = NULL;
	new->prev = stack->end;
	if (!stack->start)
		stack->start = new;
	if (stack->end)
		stack->end->next = new;
	stack->end = new;
	stack->len++;
	return (new);
}

void			lst_pop_end(t_stack *stack)
{
	t_intlst	*node;

	if (stack->start && stack->end)
	{
		node = stack->end->prev;
		ft_memdel((void**)&(stack->end));
		if (node)
			node->next = NULL;
		else
			stack->start = NULL;
		stack->end = node;
		stack->len--;
	}
}

void			lst_pop_int(t_stack *stack, int n)
{
	t_intlst	*node;

	node = stack->start;
	while (node && node->n != n)
		node = node->next;
	if (node == stack->start)
		stack->start = node->next;
	if (node == stack->end)
		stack->end = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	ft_memdel((void**)&node);
	stack->len--;
}

t_cmdlst		*cmdlst_add(t_data *data, t_cmds *cmds, char *cmd)
{
	t_cmdlst	*new;

	if (!(new = (t_cmdlst*)ft_memalloc(sizeof(t_cmdlst))))
		clean_exit(MALLOC_ERROR, data);
	ft_strcpy(new->cmd, cmd);
	new->next = NULL;
	new->prev = cmds->end;
	if (cmds->end)
		cmds->end->next = new;
	else
		cmds->start = new;
	cmds->end = new;
	cmds->len++;
	return (new);
}
