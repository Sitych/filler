/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 03:37:23 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/25 21:26:34 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_mas		ft_read_token(int fd, t_mas token)
{
	char	*line;
	int		k;
	int		j;

	k = 0;
	while (k < token.y_size)
	{
		get_next_line(fd, &line);
		j = 0;
		while (line[j])
		{
			if (line[j] == '.')
				token.mas[k][j] = 0;
			else if (line[j] == '*')
				token.mas[k][j] = -1;
			j++;
		}
		free(line);
		k++;
	}
	return (token);
}

int			ft_intersection(int y, int x, t_mas token, t_mas board)
{
	int		i;
	int		j;
	int		count;
	int		flag;

	i = 0;
	flag = 0;
	count = 0;
	while (i < token.y_size)
	{
		j = 0;
		while (j < token.x_size)
		{
			(board.mas[y + i][x + j] == token.mas[i][j]) ?\
														count = count + 1 : 0;
			(token.mas[i][j] == -1 && board.mas[y + i][x + j] == -2) ?\
																flag = 1 : 0;
			j++;
		}
		i++;
	}
	if (flag == 0 && count == 1)
		return (0);
	return (1);
}

int			ft_sum(int y, int x, t_mas board, t_mas token)
{
	int		i;
	int		j;
	int		sum;

	sum = 0;
	i = 0;
	while (i < token.y_size)
	{
		j = 0;
		while (j < token.x_size)
		{
			if (token.mas[i][j] == -1 && board.mas[y + i][x + j] != -1)
				sum = sum + board.mas[y + i][x + j];
			j++;
		}
		i++;
	}
	return (sum);
}

t_player	*ft_set_token(t_player players[2], t_mas board, t_mas token)
{
	int		i;
	int		j;
	int		min_sum;
	int		sum;

	i = -1;
	sum = 0;
	min_sum = INT32_MAX;
	while (++i <= (board.y_size - token.y_size))
	{
		j = -1;
		while (++j <= (board.x_size - token.x_size))
		{
			if (!ft_intersection(i, j, token, board))
			{
				sum = ft_sum(i, j, board, token);
				(min_sum >= sum) ? players[0].y = i : 0;
				(min_sum >= sum) ? players[0].x = j : 0;
				(min_sum >= sum) ? min_sum = sum : 0;
			}
			(min_sum == INT32_MAX) ? players[0].y = 0 : 0;
			(min_sum == INT32_MAX) ? players[0].x = 0 : 0;
		}
	}
	return (players);
}
