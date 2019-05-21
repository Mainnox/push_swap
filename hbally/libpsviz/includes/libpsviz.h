/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpsviz.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:04:27 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:05:00 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPSVIZ_H
# define LIBPSVIZ_H

# include "ps_types.h"

# define MAX_LEN 1000
# define START_WIN_WIDTH 800
# define START_WIN_HEIGHT 600
# define MAX_WIN_WIDTH 1600
# define MAX_WIN_HEIGHT 1080

# define MINI 1
# define NO_MINI 0

# define SIDE_PADDING 25
# define TOP_PADDING 40
# define MINI_PADDING 10
# define MINWIDTH 5

# define AUTOSOLVE 1
# define NO_AUTOSOLVE -1
# define REVERSE 1
# define NO_REVERSE -1
# define PREVMOVE 1
# define NO_PREVMOVE -1
# define NEXTMOVE 1
# define NO_NEXTMOVE -1
# define HIDE_NEXTMOVE 1
# define NOHIDE_NEXTMOVE -1

void			start_window(t_data *data, t_win *win);
void			exit_window(t_data *data, t_win *win, t_err error);

void			startup_viz(t_data *data);
void			get_ref(t_data *data);
void			get_window_size(t_data *data, t_win *win);
void			get_color(t_vizlst *node1, t_vizlst *node2, int16_t steps,
								int nextcolor);

void			vizlst_add(t_data *data, t_vizstack *stack, int n);
t_vizlst		*sort(t_vizlst *start);
t_vizlst		*mid(t_vizlst *start);

void			render(t_data *data, t_win *win);
void			draw_background(t_win *win);
int				draw_ui(t_data *data, t_win *win, t_cmds *cmds, char *cmd);
void			add_stack(t_data *data, t_vect anchor, t_stack *stack,
							int swap);
uint8_t			show_nextmove(t_data *data);
int				add_lastmove(t_data *data, t_win *win, char *cmd);
void			drawline(t_win *win, int color, t_vect p1, t_vect p2);

void			previous_step(t_data *data);
void			next_step(t_data *data);

int				keyboard_hooks(int keycode, void *param);
int				loop_hook(void *param);

#endif
