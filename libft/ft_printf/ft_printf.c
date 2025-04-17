/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:37:33 by srapaila          #+#    #+#             */
/*   Updated: 2024/12/02 17:13:36 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list ap, char c)
{
	int	counter;

	counter = 0;
	if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(ap, int));
	else if (c == 'c')
		counter += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(ap, char *));
	else if (c == 'u')
		counter += ft_putnbr_unsigned(va_arg(ap, int));
	else if (c == 'p')
		counter += ft_put_adress(va_arg(ap, void *));
	else if (c == 'x')
		counter += ft_putexa(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		counter += ft_putexa(va_arg(ap, unsigned int), 1);
	else if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		counter;
	int		i;

	va_start(ap, s);
	counter = 0;
	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] != '\0')
			{
				i++;
				counter += ft_check(ap, s[i]);
			}
		}
		else
			counter += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (counter);
}
// int	main()
// {
// 	int x = 42; 
//     int *ptr = &x;
// 	int i = 0 ;
// 	i = ft_printf("%% %d %i %c %s %u 
//%X %x %p\n", 1, 1, 'c', "Hello", 3, 2147483647, 111111, 0);
// 	ft_printf("%d\n", i);
//  	i = printf("%% %d %i %c %s %u %X
// %x %p\n", 1, 1, 'c', "Hello", 3, 2147483647, 111111, 0);
// 	printf("%d\n", i);
// 	 i = ft_printf("%p %p %p %p\n",L
//ONG_MAX, LONG_MIN, ULONG_MAX, -ULONG_MAX);
// 	ft_printf("%d\n", i);
// 	i = printf("%p %p %p %p\n", LONG_
//MAX, LONG_MIN, ULONG_MAX, -ULONG_MAX);
// 	printf("%d\n", i);
// 	return (0);
// }
