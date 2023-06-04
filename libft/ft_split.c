/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:50:12 by bsengeze          #+#    #+#             */
/*   Updated: 2022/12/22 18:36:12 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_substrcnt(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_substrcnt(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}
/*
int main(void)
{
	int i;
	char **ret;

	ret = ft_split("ABC,,A", ',');

for(i = 0; i <= 100; i++)
  {
    printf("\n Element %d is: %s \n", i,ret[i]);
  }
}
*/
