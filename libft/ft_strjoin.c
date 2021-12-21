/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:05:43 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/15 16:54:56 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (*str2)
	{
		str[i] = *str2;
		str2++;
		i++;
	}
	str[i] = '\0';
	free(str1);
	return (str);
}
