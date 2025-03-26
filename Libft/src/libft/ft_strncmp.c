/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:57:43 by macaruan          #+#    #+#             */
/*   Updated: 2024/11/22 12:32:11 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *sec, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && first[i] == sec[i])
	{
		if (first[i] == '\0')
			return (0);
		i++;
	}
	if (i == len)
		return (0);
	return ((unsigned char)first[i] - (unsigned char)sec[i]);
}
// int	main()
// {
// 	const char	fi[] = "hello";
// 	const char	sc[] = "helli";

// 	printf("%d\n", ft_strncmp(fi, sc, 4));

// 	return (0);
// }
