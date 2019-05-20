/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:09:37 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:10:00 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libpushswap.h"
#include "libft.h"

static int		has_whitespace(const char *string)
{
	size_t		i;

	i = 0;
	while (string[i])
	{
		if ((string[i] >= 7 && string[i] <= 13) || string[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static void		add_option(const char c, t_opt_u *opt, char *msg)
{
	int			i;

	i = ft_strchri("v", c);
	if (i == -1)
	{
		ft_printf(msg);
		exit(EXIT_FAILURE);
	}
	opt->data[i] = 1;
}

static int		is_option(t_data *data, const char *string)
{
	size_t		i;
	uint8_t		has_digits;
	uint8_t		has_others;

	i = 1;
	has_others = 0;
	has_digits = 0;
	if (string[0] != '-' || has_whitespace(string))
		return (0);
	while (string[i])
	{
		if (ft_isdigit(string[i]))
			has_digits = 1;
		else
			has_others = 1;
		i++;
	}
	if (has_digits && has_others)
		clean_exit(GETARG_BADFORMAT, data);
	if (has_digits && !has_others)
		return (0);
	else
		return (1);
}

static int		parse_options(t_data *data, int argc, char **argv, char *msg)
{
	int			i;
	int			j;

	i = 1;
	while (i < argc && is_option(data, argv[i]))
	{
		j = 1;
		while (argv[i][j])
		{
			add_option(argv[i][j], &(data->options), msg);
			j++;
		}
		i++;
	}
	return (i);
}

void			get_options(t_data *data, int argc, char **argv, char *msg)
{
	data->args.tab = argv;
	data->args.len = argc;
	data->args.pos = parse_options(data, argc, argv, msg);
	if (data->args.pos == (size_t)(data->args.len))
		clean_exit(NO_ERROR, data);
}
