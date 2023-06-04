/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:55 by bsengeze          #+#    #+#             */
/*   Updated: 2022/12/24 17:07:42 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	while (len > i)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = 0;
	return (p);
}
/*
int main(void)
{

printf("= %s",ft_substr("hola", 4294967295, 0));
}
*/
