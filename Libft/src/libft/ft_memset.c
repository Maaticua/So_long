/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:58:19 by maati             #+#    #+#             */
/*   Updated: 2024/11/28 11:50:33 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t count)
{
	unsigned char	*start;

	start = (unsigned char *)p;
	while (count)
	{
		*start = (unsigned char)value;
		start++;
		count--;
	}
	return (p);
}
// int	main()
// {
// 	char	str[] = "Bonjours les cons";

// 	printf("%s\n", str);

// 	ft_memset(str, 'X', 10);

// 	printf("%s\n", str);
// 	return (0);
// }
