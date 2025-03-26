/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:10:02 by maati             #+#    #+#             */
/*   Updated: 2024/11/28 11:49:44 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int chara)
{
	if (chara >= 'a' && chara <= 'z')
		return (chara - 32);
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
