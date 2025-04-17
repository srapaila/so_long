/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:21:43 by srapaila          #+#    #+#             */
/*   Updated: 2024/12/02 16:25:22 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_adress(void *ptr)
{
	int	re;

	re = 0;
	if (!ptr)
		return (re += ft_putstr("(nil)"));
	re += ft_putstr("0x");
	re += ft_putptr((unsigned long) ptr);
	return (re);
}
