#include "libft.h"

int	ft_arraylen(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
