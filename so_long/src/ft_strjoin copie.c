
#include "so_long.h"

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char		*str;
	int		i;
	int		size;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = strlen(s1) + strlen(s2) + 1;
	str = malloc((sizeof(char) * size));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
