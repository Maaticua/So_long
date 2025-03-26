/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:02:02 by macaruan          #+#    #+#             */
/*   Updated: 2024/12/04 16:03:59 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function is used to print pointers
int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	tmp;

	len = 0;
	tmp = (unsigned long)ptr;
	if (tmp == 0)
		len += ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		if (tmp >= 16)
			len += ft_puthexad(tmp / 16, 'x');
		len += ft_putchar("0123456789abcdef"[tmp % 16]);
	}
	return (len);
}
