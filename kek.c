/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kek.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 02:40:11 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/08 03:33:49 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_mas(t_mas board)
{
	ft_printf("x_szie = %d y_size = %d\n", board.x_size, board.y_size);
	ft_printf("   ");
	for(int i = 0; i < board.x_size; i++)
		ft_printf("%2d ", i);
	ft_printf("\n");
	for(int i = 0; i < board.y_size; i++)
	{
		ft_printf("%2d ", i);
		for(int j = 0; j < board.x_size; j++)
			ft_printf("%2d ", board.mas[i][j]);
		ft_printf("\n");
	}
}
