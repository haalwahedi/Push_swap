/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:00:50 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 15:00:51 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_sort_nbr(int *arr, int len)
{
	int		i;
	int		j;
	int		tmp;
	int		*ret;

	ret = malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		ret[i] = arr[i];
	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (ret[i] > ret[j])
			{
				tmp = ret[i];
				ret[i] = ret[j];
				ret[j] = tmp;
			}
		}
	}
	return (ret);
}
