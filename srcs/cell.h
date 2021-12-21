/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:51:21 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/21 01:57:42 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_H
# define CELL_H

# include "libft.h"
# include <stdlib.h>

typedef struct s_world
{
	int	size;
	int	*matter;
}	t_world;

void	tomorrow(char states[2], t_world prev_world,
			int rule[8], int doomsday);
void	dawn(t_world *today, t_world *yesterday, int *gods_memory, int *rule);

int		*int_to_rules(int encoded_rules);

t_world	str_to_world(char states[2], char *encoded_wolrd);

#endif
