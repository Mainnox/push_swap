/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:46:49 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:11:37 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"

static void		check_duplicate(t_data *data, t_intlst *start, int32_t n)
{
	t_intlst	*elem;

	elem = start;
	while (elem)
	{
		if (elem->n == n)
			clean_exit(GETARG_DUP, data);
		elem = elem->next;
	}
}

static uint8_t	check_spaces(t_data *data, char *string)
{
	size_t		i;
	uint8_t		found_space;

	i = 0;
	found_space = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]) && !(ft_strchr(" -+", string[i])))
			clean_exit(GETARG_BADFORMAT, data);
		if (string[i] == ' ')
			found_space = 1;
		i++;
	}
	return (found_space);
}

static int32_t	get_number(t_data *data, char *string)
{
	size_t		i;
	int			n;

	n = ft_atoi(string);
	i = 0;
	if (string[0] == '-' || string[0] == '+')
		i++;
	if (n == 0 && !(string[i] && (string[i] == '0' && string[i + 1] == '\0')))
		clean_exit(GETARG_BADFORMAT, data);
	while (ft_isdigit(string[i]))
		i++;
	if (string[i] != '\0')
		clean_exit(GETARG_BADFORMAT, data);
	return (n);
}

static void		split_subargs(t_data *data, char *subargs)
{
	if ((data->subargs.tab = ft_strsplit(subargs, ' ')) == NULL)
		clean_exit(MALLOC_ERROR, data);
	while (data->subargs.tab[data->subargs.len])
		data->subargs.len++;
	data->subargs.pos = 0;
	stack_get(data, &(data->subargs));
	free_arglist(&(data->subargs));
}

void			stack_get(t_data *data, t_arglist *args)
{
	int32_t		n;

	while (args->pos < (size_t)args->len)
	{
		if (check_spaces(data, args->tab[args->pos]))
			split_subargs(data, args->tab[args->pos]);
		else
		{
			n = get_number(data, args->tab[args->pos]);
			check_duplicate(data, data->a.start, n);
			lst_add(data, &(data->a), n);
		}
		args->pos++;
	}
}
