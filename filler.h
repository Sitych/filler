/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:18:40 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/11 21:08:01 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libftprintf.h"

# define NAME "qjosmyn"

typedef struct			s_player
{
	char				letter;
	int					x;
	int					y;
}						t_player;

typedef struct			s_mas
{
	int					x_size;
	int					y_size;
	int					**mas;
}						t_mas;

typedef struct			s_mindist
{
	int					dist;
	struct s_mindist	*next;
}						t_mindist;

char					*ft_go_to_map_size(int fd);
void					ft_solver(int fd, t_player players[2]);
t_mas					ft_read_map(int fd, t_mas board, t_player players[2],
																char **line);
t_mas					ft_creat(int x, int y);
t_mas					ft_distance(t_mas board);
int						ft_srchmin(t_mas board, int i, int j);
t_mas					ft_read_token(int fd, t_mas token);
t_player				*ft_set_token(t_player players[2], t_mas board,
																t_mas token);
t_mas					ft_read_token(int fd, t_mas token);
int						ft_intersection(int y, int x, t_mas token, t_mas board);
int						ft_sum(int y, int x, t_mas board, t_mas token);
void					ft_null(char ***str, char **line, t_mas *board,
																t_mas *token);
int						ft_abs(int x);
t_player				*ft_algorithm(int fd, t_mas board, t_mas token,
														t_player players[2]);
t_mas					ft_board(int fd, t_mas board, t_player players[2]);

#endif
