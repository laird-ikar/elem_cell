/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:49:31 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/21 01:57:33 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell.h"

int	main(int ac, char *av[])
{
	int		*rules;
	t_world	world;

	rules = int_to_rules(ft_atoi(av[3]));
	world = str_to_world(av[1], av[2]);
	if (ac == 5 && world.size != -42)
		tomorrow(av[1],
			world,
			rules,
			ft_atoi(av[4]));
	else
		ft_putstr("Please indicate the charset that represent \e[1;31mdead\e[m \
then \e[1;32malive\e[m,\ninitial \e[1;34mworld\e[m with that atoms and \
\e[1;35mrule\e[m and finaly the \e[1;90mdoomsday\e[m\n\t\
Exemple : \n\n\t ./elem_cell \"\e[31m.\e[32m#\e[m\" \"\e[34m...#...\e[m\" \
\e[35m110\e[m \e[0;90m42\e[m\n");
	free(rules);
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
		dawn(&today, &yesterday, &gods_memory, rule);
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

void	dawn(t_world *today, t_world *yesterday, int *gods_memory, int *rule)
{
	int	i;

	i = 0;
	while (i < today->size)
	{
		if (i == 0 && i == today->size - 1)
			*gods_memory = rule[yesterday->matter[i] * 2];
		else if (i == 0)
			*gods_memory = rule[yesterday->matter[i] * 2
				+ yesterday->matter[i + 1]];
		else if (i == today->size - 1)
			*gods_memory = rule[yesterday->matter[i - 1] * 4
				+ yesterday->matter[i] * 2];
		else
			*gods_memory = rule[yesterday->matter[i - 1] * 4
				+ yesterday->matter[i] * 2
				+ yesterday->matter[i + 1]];
		today->matter[i++] = *gods_memory;
	}
}
