/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:11:07 by srapaila          #+#    #+#             */
/*   Updated: 2024/12/11 18:53:30 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_check(va_list ap, char c);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putexa(unsigned int n, int isupper);
int	ft_put_adress(void *ptr);
int	ft_putptr(unsigned long n);

#endif