/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:46:04 by srapaila          #+#    #+#             */
/*   Updated: 2024/12/02 17:10:56 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putexa(unsigned int n, int isupper)
{
	char	*base;
	int		re;

	re = 0;
	if (isupper == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		re += ft_putexa(n / 16, isupper);
	re += ft_putchar(base[n % 16]);
	return (re);
}
