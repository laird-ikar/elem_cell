/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:32:49 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/20 22:40:07 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_srand(unsigned int seed);

char	ft_getchar(void);

int		ft_rand(void);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_isspace(char c);

char	*ft_strcat(char *dest, char *src);

#endif
