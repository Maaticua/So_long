/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexad.c                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:54:46 by macaruan          #+#    #+#             */
/*   Updated: 2024/12/04 15:56:32 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function is used to print hexadecimal numbers
int	ft_puthexad(unsigned long n, char norm)
{
	int		len;
	char	*hexa;

	len = 0;
	if (norm == 'x')
		hexa = "0123456789abcdef";
	else if (norm == 'X')
		hexa = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthexad(n / 16, norm);
	len += ft_putchar(hexa[n % 16]);
	return (len);
}
