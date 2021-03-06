/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:49:31 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/21 12:57:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell.h"

int	main(int ac, char *av[])
{
	int		*rules;
	t_world	world;

	rules = NULL;
	world.matter = NULL;
	if (ac == 5)
	{
		rules = int_to_rules(ft_atoi(av[3]));
		world = str_to_world(av[1], av[2]);
		if (world.size != -42)
			tomorrow(av[1],
				world,
				rules,
				ft_atoi(av[4]));
	}
	else
		ft_putstr("Please indicate the charset that represent \e[1;31mdead\e[m \
then \e[1;32malive\e[m,\ninitial \e[1;34mworld\e[m with that atoms and \
\e[1;35mrule\e[m and finaly the \e[1;90mdoomsday\e[m\n\t\
Exemple : \n\n\t ./elem_cell \"\e[31m.\e[32m#\e[m\" \"\e[34m...#...\e[m\" \
\e[35m110\e[m \e[0;90m42\e[m\n");
	if (rules)
		free(rules);
	if (world.matter)
		free(world.matter);
	return (0);
}

void	tomorrow(char atoms[2], t_world yesterday,
	int *rule, int doomsday)
{
	t_world	today;
	int		i;
	int		gods_memory;

	i = 0;
	today.matter = NULL;
	while (i < yesterday.size)
		ft_putchar(atoms[yesterday.matter[i++]]);
	ft_putchar('\n');
	if (doomsday > 0 && yesterday.size)
	{
		today.size = yesterday.size;
		today.matter = malloc(sizeof(int) * today.size);
		i = 0;
		while (i < today.size)
		{
			gods_memory = yesterday.matter[i] * 2
				+ (i != today.size - 1) * yesterday.matter[i + 1]
				+ (i != 0) * yesterday.matter[i - 1] * 4;
			today.matter[i++] = rule[gods_memory];
		}
		tomorrow(atoms, today, rule, doomsday - 1);
	}
	if (today.matter)
		free (today.matter);
}

t_world	str_to_world(char atoms[2], char *encoded_wolrd)
{
	t_world	first_day;
	int		i;

	first_day.size = 0;
	while (encoded_wolrd[first_day.size])
	{
		first_day.size++;
	}
	first_day.matter = malloc(sizeof(int) * first_day.size);
	i = 0;
	while (i < first_day.size)
	{
		if (encoded_wolrd[i] == atoms[0])
			first_day.matter[i] = 0;
		else if (encoded_wolrd[i] == atoms[1])
			first_day.matter[i] = 1;
		else
		{
			first_day.size = -42;
			return (first_day);
		}
		i++;
	}
	return (first_day);
}

int	*int_to_rules(int encoded_rules)
{
	int	*rules;
	int	i;

	rules = malloc(sizeof(int) * 8);
	i = 7;
	while (i >= 0)
	{
		rules[7 - i] = encoded_rules % 2;
		encoded_rules /= 2;
		i--;
	}
	return (rules);
}
