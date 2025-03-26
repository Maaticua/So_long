/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:39:40 by macaruan          #+#    #+#             */
/*   Updated: 2024/11/16 17:16:31 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i++] = '\0';
	}
}

// int main()
// {
//     int s[5] = {1, 2, 3, 4, 5};

//     printf("%d %d %d %d %d\n", s[0], s[1], s[2], s[3], s[4]);

//     ft_bzero(s, sizeof(s));

//     printf("%d %d %d %d %d\n", s[0], s[1], s[2], s[3], s[4]);

//     return 0;
// }
