/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:39:26 by srapaila          #+#    #+#             */
/*   Updated: 2024/11/29 18:00:33 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	re;

	re = 0;
	if (n == -2147483648)
	{
		return (write (1, "-2147483648", 11));
	}
	if (n < 0)
	{
		re += write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		re += ft_putnbr (n / 10);
		re += ft_putnbr (n % 10);
	}
	else
		re += ft_putchar(n + 48);
	return (re);
}
/*
int	main(void)
{
	ft_putnbr (-2147483648);
}*/
