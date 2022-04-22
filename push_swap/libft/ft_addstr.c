/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:58:55 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 14:58:56 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addstr(char ***arr, char *str)
{
	char		**tmp;
	int			len;
	int			i;

	len = ft_arraylen(*arr);
	tmp = malloc(sizeof(char *) * (len + 2));
	tmp[len + 1] = NULL;
	tmp[len] = str;
	i = -1;
	while (*(*arr + ++i))
		tmp[i] = *(*arr + i);
	free(*arr);
	*arr = tmp;
}