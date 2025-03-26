/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:42:22 by maati             #+#    #+#             */
/*   Updated: 2024/11/28 11:49:54 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int chara)
{
	if (chara >= 'A' && chara <= 'Z')
		return (chara + 32);
	return (chara);
}
// int main(int ac, char *av[])
// {
//     char input = av[1][0];
//     if (ac != 2)
//         return(0);
//     printf("%c\n", ft_troupper(input));
//     return (0);
// }
