/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:58:02 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 10:35:07 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int		map_error(void)
{
	write(2, "map error\n", 10);
	return (0);
}
