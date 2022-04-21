#include "libft.h"

void	ft_free_arg(char **arg)
{
	if (*arg)
		free(*arg);
	*arg = NULL;
}

char	**ft_free(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
