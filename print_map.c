/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:02:25 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 10:11:16 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"
#include "transform.h"
#include <unistd.h>

void			print_map(t_map *map, t_solution *solution)
{
	char	buf[BUF_SIZE];
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (i == BUF_SIZE)
			{
				i = 0;
				write(1, buf, BUF_SIZE);
			}
			char c = transform_from(x++, y, map, solution);
			buf[i++] = c;
		}
		if (i == BUF_SIZE)
		{
			i = 0;
			write(1, buf, BUF_SIZE);
		}
		buf[i++] = '\n';
		y++;
	}
	if (i > 0)
		write(1, buf, i);
}
