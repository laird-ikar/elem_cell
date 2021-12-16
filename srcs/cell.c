/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:49:31 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/16 21:10:54 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell.h"

int	main(int ac, char *av[])
{
	if (ac == 4)
		run_automata(av[1], state(av[2], av[1]), rule_tab(ft_atoi(av[3])));
	else
	{
		ft_putstr("Please indicate the char that represent alive, ");
		ft_putstr("initial state with that char and space and rule number\n");
		ft_putstr("\tExemple : \n\n\t ./elem_cell # \"     #       \" 110\n");
	}
	return (0);
}
