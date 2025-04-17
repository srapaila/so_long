/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:19:22 by srapaila          #+#    #+#             */
/*   Updated: 2024/11/29 18:00:35 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	re;

	re = 0;
	if (n < 10)
		re += ft_putchar(n + 48);
	else
	{
		re += ft_putnbr (n / 10);
		re += ft_putnbr (n % 10);
	}
	return (re);
}
