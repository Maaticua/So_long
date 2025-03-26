/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:51:11 by maati             #+#    #+#             */
/*   Updated: 2024/12/04 16:29:06 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_norms(va_list args, const char norms)
{
	int	count;

	count = 0;
	if (norms == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (norms == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (norms == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (norms == 'd' || norms == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (norms == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (norms == 'x' || norms == 'X')
		count += ft_puthexad(va_arg(args, unsigned int), norms);
	else if (norms == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_norms(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
