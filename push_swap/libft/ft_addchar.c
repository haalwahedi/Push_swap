/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:58:52 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 14:58:53 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchar(char *str, char c)
{
	char		*res;
	int			len;
	int			i;

	i = -1;
	len = ft_strlen(str);
	res = ft_calloc(len + 2, sizeof(char));
	while (++i < len)
		res[i] = str[i];
	res[i] = c;
	free(str);
	return (res);
}
