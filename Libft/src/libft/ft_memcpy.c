/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:04:12 by macaruan          #+#    #+#             */
/*   Updated: 2024/11/28 11:50:41 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main()
// {
// 	size_t i;
// 	const char src[] = "Bonjour les cons";
// 	char dest[100];

// 	i = 40;

// 	printf("%s\n", src);
// 	printf("%s\n", dest);

// 	ft_memcpy(dest, src, i);

// 	printf("%s\n", src);
// 	printf("%s\n", dest);
//	return (0);
// }
