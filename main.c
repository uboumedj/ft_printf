/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:21:55 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/12 11:20:58 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("Hello world, %hh#s lol %s\n", "salut", "merde");
	ft_printf("Test nombre %d haha\n", 42);
	ft_printf("test caractere %c %c\n", 'b', 66);
	printf("Test printf short %k %hd %ld\n", 2147, 2147, 2147);
	return (0);
}
