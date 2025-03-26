/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:41:48 by macaruan          #+#    #+#             */
/*   Updated: 2024/11/28 12:02:57 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	strr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!strr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		strr[i] = f(i, s[i]);
		i++;
	}
	strr[i] = '\0';
	return (strr);
}

// char my_toupper(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main()
// {
// 	char *s = "Bonjour les cons";
// 	char *str = ft_strmapi(s, my_toupper);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
