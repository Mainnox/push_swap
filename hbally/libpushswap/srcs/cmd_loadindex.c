/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loadindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:46:41 by hbally            #+#    #+#             */
/*   Updated: 2019/01/27 16:46:42 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"

static void		update(t_cmdindex *index, size_t pos, char *str, t_cmd_ft ptr)
{
	ft_strcpy(index[pos].cmd_str, str);
	index[pos].cmd_ft = ptr;
	if (ft_strchr(str, 'a'))
		index[pos].flag = EDIT_A;
	else if (ft_strchr(str, 'b'))
		index[pos].flag = EDIT_B;
	else
		index[pos].flag = EDIT_A + EDIT_B;
}

/*
**	In case new commands are added, update the CMDINDEX_SIZE macro in
**	libpushswap.h accordingly.
*/

void			cmd_loadindex(t_data *data)
{
	update(data->index, 0, "sa", &swap);
	update(data->index, 1, "sb", &swap);
	update(data->index, 2, "ss", &swap);
	update(data->index, 3, "pa", &push);
	update(data->index, 4, "pb", &push);
	update(data->index, 5, "ra", &rotate);
	update(data->index, 6, "rb", &rotate);
	update(data->index, 7, "rr", &rotate);
	update(data->index, 8, "rra", &revrotate);
	update(data->index, 9, "rrb", &revrotate);
	update(data->index, 10, "rrr", &revrotate);
}
