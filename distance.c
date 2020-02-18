/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:30:58 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/11 20:36:39 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_srchmin(t_mas board, int i, int j)
{
	int			min;
	int			dist;
	int			x;
	int			y;

	min = INT32_MAX;
	y = 0;
	while (y < board.y_size)
	{
		x = 0;
		while (x < board.x_size)
		{
			if (board.mas[y][x] == -2)
			{
				dist = ft_abs(j - x) + ft_abs(i - y);
				min = (min > dist) ? dist : min;
			}
			x++;
		}
		y++;
	}
	return (min);
}

t_mas	ft_distance(t_mas board)
{
	int			i;
	int			j;

	i = 0;
	while (i < board.y_size)
	{
		j = 0;
		while (j < board.x_size)
		{
			if (board.mas[i][j] == -1 || board.mas[i][j] == -2)
			{
				j++;
				continue ;
			}
			board.mas[i][j] = ft_srchmin(board, i, j);
			j++;
		}
		i++;
	}
	return (board);
}

int		ft_abs(int x)
{
	if (x >= 0)
		return (x);
	else
		return ((-1) * x);
}

void	ft_null(char ***str, char **line, t_mas *board, t_mas *token)
{
	*str = NULL;
	*line = NULL;
	board->mas = NULL;
	board->x_size = 0;
	board->y_size = 0;
	token->mas = NULL;
	token->x_size = 0;
	token->y_size = 0;
}
