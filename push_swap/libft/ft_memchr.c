/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:32:32 by halwahed          #+#    #+#             */
/*   Updated: 2021/10/13 12:45:00 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*pt;

	pt = (char *)s;
	while (n > 0)
	{
		if (*pt == (char)c)
			return (pt);
		pt++;
		n--;
	}
	return (0);
}
