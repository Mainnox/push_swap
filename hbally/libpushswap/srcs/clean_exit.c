/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:19:58 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:50:32 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"
#include "libpushswap.h"

void			free_arglist(t_arglist *args)
{
	size_t		i;

	i = 0;
	while (args->tab[i])
	{
		ft_memdel((void**)&(args->tab[i]));
		i++;
	}
	ft_memdel((void**)args->tab);
}

static void		free_cmdlst(t_cmdlst *start)
{
	t_cmdlst	*elem;
	t_cmdlst	*previous;

	if (start)
	{
		elem = start->next;
		while (elem)
		{
			previous = elem;
			elem = elem->next;
			ft_memdel((void**)&(previous));
		}
		ft_memdel((void**)&(start));
	}
}

void			free_stack(t_stack *s)
{
	t_intlst	*elem;
	t_intlst	*previous;

	if (s->start)
	{
		elem = s->start->next;
		while (elem)
		{
			previous = elem;
			elem = elem->next;
			ft_memdel((void**)&(previous));
		}
		ft_memdel((void**)&(s->start));
	}
	s->end = NULL;
	s->len = 0;
}


void			clean_exit(t_err error, t_data *data)
{
	free_stack(&(data->a));
	free_stack(&(data->b));
	free_stack(&(data->c));
	free_cmdlst(data->cmds.start);
	if (data->subargs.tab)
		free_arglist(&(data->subargs));
	if (data->win)
		ft_memdel((void**)&(data->win));
	if (error)
	{
		ft_dprintf(2, "Error\n");
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
