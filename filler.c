/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:32:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/11 21:09:07 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_go_to_map_size(int fd)
{
	char	*line;
	int		flag;

	line = NULL;
	flag = get_next_line(fd, &line);
	while (flag == 1)
	{
		if (ft_strrchr(line, 'P'))
			break ;
		free(line);
		flag = get_next_line(fd, &line);
	}
	if (flag == -1)
		return (NULL);
	return (line);
}

void		ft_solver(int fd, t_player players[2])
{
	char	*line;
	char	**str;
	t_mas	token;
	t_mas	board;

	ft_null(&str, &line, &board, &token);
	while (1)
	{
		line = ft_go_to_map_size(fd);
		str = ft_strsplit(line, ' ');
		free(line);
		if (!board.mas)
			board = ft_creat(ft_atoi(str[2]), ft_atoi(str[1]));
		ft_free((void**)str, 3);
		board = ft_distance(ft_read_map(fd, board, players, &line));
		str = ft_strsplit(line, ' ');
		free(line);
		token = ft_creat(ft_atoi(str[2]), ft_atoi(str[1]));
		ft_free((void**)str, 3);
		token = ft_read_token(fd, token);
		players = ft_set_token(players, board, token);
		ft_printf("%d %d\n", players[0].y, players[0].x);
		if (players[0].x == -1 && players[0].y == -1)
			break ;
	}
}

t_mas	ft_creat(int x, int y)
{
	t_mas	board;

	board.mas = ft_twodemint(x, y);
	board.x_size = x;
	board.y_size = y;
	return (board);
}

t_mas	ft_read_map(int fd, t_mas board, t_player players[2], char **line)
{
	char	**str;
	int		i;
	int		j;

	while (get_next_line(fd, line) > 0 && !ft_strrchr(*line, '0') && !(i = 0))
		free(*line);
	free(*line);
	while (get_next_line(fd, line) > 0 && !ft_strrchr(*line, 'P'))
	{
		j = 0;
		str = ft_strsplit(*line, ' ');
		while (str[1][j] != 0)
		{
			if (str[1][j] == players[0].letter || \
									str[1][j] == ft_toupper(players[0].letter))
				board.mas[i][j] = -1;
			else if (str[1][j] == players[1].letter || \
									str[1][j] == ft_toupper(players[1].letter))
				board.mas[i][j] = -2;
			j++;
		}
		ft_free((void**)str, 2);
		i++;
	}
	return (board);
}

int		main(void)
{
	char		*line;
	t_player	players[2];
	int			fd;

	fd = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strrchr(line, '$'))
			break ;
		free(line);
	}
	players[0].letter = 'x';
	players[1].letter = 'x';
	if (ft_strstr(line, NAME) && ft_strstr(line, "p1"))
		players[0].letter = 'o';
	else
		players[1].letter = 'o';
	free(line);
	ft_solver(fd, players);
	return (0);
}
