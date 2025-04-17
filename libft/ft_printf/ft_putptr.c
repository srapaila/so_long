/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:23:51 by srapaila          #+#    #+#             */
/*   Updated: 2024/12/02 16:26:29 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	char	*base;
	int		re;

	re = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		re += ft_putptr(n / 16);
	re += ft_putchar(base[n % 16]);
	return (re);
}
