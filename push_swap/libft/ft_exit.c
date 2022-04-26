/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:59:07 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 14:59:08 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	else
		ft_putstr_fd("exit\n", 1);
	exit(err);
}
