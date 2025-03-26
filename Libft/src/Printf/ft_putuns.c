/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maati <maati@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-05 10:40:29 by maati             #+#    #+#             */
/*   Updated: 2024-12-05 10:40:29 by maati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function is used to print unsigned integers
int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	c = (n % 10) + '0';
	len += ft_putchar(c);
	return (len);
}
