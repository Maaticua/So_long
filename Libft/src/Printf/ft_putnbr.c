/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:42:40 by macaruan          #+#    #+#             */
/*   Updated: 2024/12/04 15:42:54 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function is used to print integers
int	ft_putnbr(int n)
{
	int		len;
	char	buffer[12];
	int		i;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	i = 0;
	while (n >= 10)
	{
		buffer[i++] = (n % 10) + '0';
		n = n / 10;
	}
	buffer[i++] = n + '0';
	while (--i >= 0)
		len += ft_putchar(buffer[i]);
	return (len);
}
