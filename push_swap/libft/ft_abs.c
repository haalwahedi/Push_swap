/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:58:46 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 14:58:47 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(float num)
{
	int	dummy;

	dummy = (int)num;
	if ((num - dummy) >= 0.5)
		return ((int) num + 1);
	else
		return ((int) num);
}
