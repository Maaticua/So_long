/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: macaruan <macaruan@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/27 13:06:14 by macaruan		  #+#	#+#			 */
/*   Updated: 2024/11/27 13:12:07 by macaruan		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static char	*allocate_word(char const *s, size_t j, size_t i)
{
	char	*word;

	word = malloc(i - j + 1);
	if (word)
		ft_strlcpy(word, &s[j], i - j + 1);
	return (word);
}

static void	*free_split(char **res, size_t k)
{
	while (k--)
		free(res[k]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	utils[4];

	utils[2] = ((utils[0] = 0));
	utils[3] = ft_countwords(s, c);
	res = malloc(sizeof(char *) * (utils[3] + 1));
	if (!res)
		return (NULL);
	while (s[utils[0]])
	{
		while (s[utils[0]] && s[utils[0]] == c)
			utils[0]++;
		utils[1] = utils[0];
		while (s[utils[0]] && s[utils[0]] != c)
			utils[0]++;
		if (utils[0] > utils[1])
		{
			res[utils[2]] = allocate_word(s, utils[1], utils[0]);
			if (!res[utils[2]++])
				return (free_split(res, utils[2] - 1));
		}
	}
	res[utils[2]] = NULL;
	return (res);
}
// int main()
// {
// 	char *s = "Bonjour les cons";
// 	char **str = ft_split(s, ' ');
// 	for (int i = 0; str[i]; i++)
// 		printf("%s\n", str[i]);
// 	free(str);
// 	return (0);
// }
