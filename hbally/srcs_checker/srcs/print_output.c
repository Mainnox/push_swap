/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:01:09 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:00:40 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"
#include "libpsviz.h"
#include "checker.h"

void				print_output(t_data *data)
{
	if (data->options.index.viz && data->a.len <= MAX_LEN)
	{
		if ((data->win = (t_win*)ft_memalloc(sizeof(t_win))) == NULL)
			clean_exit(MALLOC_ERROR, data);
		startup_viz(data);
	}
	else
	{
		if (data->options.index.viz)
			ft_printf("[\'-v\' : Input size must be between 1 and %d]\n",
							MAX_LEN);
		cmd_applylist(data);
		ft_printf(check_stacks(&(data->a), &(data->b)) ? "OK\n" : "KO\n");
	}
}
