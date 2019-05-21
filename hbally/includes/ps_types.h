/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:30:29 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:31:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_TYPES_H
# define PS_TYPES_H

# include <stdint.h>
# include <string.h>

# define CMDINDEX_SIZE 11

/*
** Viz types
*/

typedef struct			s_vect
{
	int16_t				x;
	int16_t				y;
}						t_vect;

typedef struct			s_img
{
	void				*self_id;
	char				*data;
	int					bpp;
	int					line_size;
	int					endian;
}						t_img;

typedef struct			s_vizlst
{
	int					n;
	int16_t				width;
	int16_t				height;
	int					color;
	struct s_vizlst		*next;
}						t_vizlst;

typedef struct			s_vizstack
{
	t_vizlst			*start;
	t_vizlst			*q1;
	t_vizlst			*mid;
	t_vizlst			*q3;
	t_vizlst			*end;
	size_t				len;
}						t_vizstack;

typedef struct			s_win
{
	void				*self_id;
	void				*mlx_id;
	t_img				img;
	t_vizstack			ref;
	t_vect				a_top;
	t_vect				a_anchor;
	t_vect				b_top;
	t_vect				b_anchor;
	int16_t				width;
	int16_t				height;
	int16_t				top_pad;
	int16_t				side_pad;
	int16_t				mini;
	int16_t				max_len;
	int16_t				bar_minwidth;
	int16_t				bar_maxwidth;
	int16_t				bar_step;
	int16_t				bar_height;
	int16_t				batch;
	int16_t				autosolve;
	int16_t				reverse;
	int16_t				nextmove;
	int16_t				prevmove;
	int16_t				hide_nextmove;
}						t_win;

typedef int8_t			t_err;
typedef uint8_t			t_flag;

/*
** Arguments storage
*/

typedef struct			s_arglist
{
	char				**tab;
	int					len;
	size_t				pos;
}						t_arglist;

typedef struct			s_opt
{
	uint8_t				viz;
}						t_opt;

typedef union			u_opt
{
	uint8_t				data[2];
	t_opt				index;
}						t_opt_u;

/*
** Data Storage => Double linked list for numbers, Linked list for cmds
*/

typedef struct			s_intlst
{
	int32_t				n;
	struct s_intlst		*next;
	struct s_intlst		*prev;
}						t_intlst;

typedef struct			s_cmdlst
{
	char				cmd[4];
	struct s_cmdlst		*next;
	struct s_cmdlst		*prev;
}						t_cmdlst;

/*
** Data containers w/ useful extra info
*/

typedef struct			s_stack
{
	char				id;
	struct s_stack		*opp;
	t_intlst			*start;
	t_intlst			*end;
	size_t				len;
}						t_stack;

typedef struct			s_cmds
{
	t_cmdlst			*start;
	t_cmdlst			*end;
	t_cmdlst			*pos;
	uint8_t				at_start;
	uint8_t				at_end;
	size_t				len;
	size_t				step_number;
}						t_cmds;

/*
**  Function pointer array to access commands easily from a string
*/

typedef	void			(*t_cmd_ft)(t_stack*, t_stack*, t_flag);

typedef struct			s_cmdindex
{
	char				cmd_str[4];
	t_flag				flag;
	t_cmd_ft			cmd_ft;
}						t_cmdindex;

/*
** Main data container, passed throughout
*/

typedef struct			s_data
{
	t_arglist			args;
	t_opt_u				options;
	t_arglist			subargs;
	t_cmdindex			index[CMDINDEX_SIZE];
	t_stack				a;
	t_stack				b;
	t_stack				c;
	int					min;
	size_t				endlen;
	t_cmds				cmds;
	t_win				*win;
}						t_data;
#endif
