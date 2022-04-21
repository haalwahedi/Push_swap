#include "libft.h"

void	ft_intcpy(int *src, int *dst, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
