/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:02:45 by maati             #+#    #+#             */
/*   Updated: 2025/02/19 14:54:28 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}

// int main(void)
// {
// 	const char str[] = "Hello, world!";
// 	char c = 'o';
// 	char *result;

// 	result = ft_strchr(str, c);
// 	if (result)
// 		printf("The first of '%c' position: %ld\n", c, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", c);

// 	return 0;
// }
