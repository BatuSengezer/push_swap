/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:33:15 by bsengeze          #+#    #+#             */
/*   Updated: 2022/12/22 21:58:12 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] -(unsigned char)s2[i]);
		if (s1[i] == s2[i])
			i++;
		n--;
	}
	return (0);
}
/*
int main(void)
{
	printf("result : %d\n", ft_strncmp("test\200", "test\0", 6));
	printf("result : %d", strncmp("test\200", "test\0", 6));
}
*/
