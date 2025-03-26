/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:21:55 by maati             #+#    #+#             */
/*   Updated: 2024/11/28 11:50:18 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

// int main()
// {
//     char dest[50];
//     const char  src[] = "Bonjour les cons";
//     size_t len = ft_strlcpy(dest, src, sizeof(dest));

//     printf("%s\n", src);
//     printf("%s\n", dest);

//     ft_strlcpy(dest, src, sizeof(dest));

//     printf("%s\n", src);
//     printf("%s\n", dest);
//     printf("%ld", len);

//     return (0);
// }
