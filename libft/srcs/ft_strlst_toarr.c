
#include "libft.h"

char	**ft_strlst_toarr(t_list *lst)
{
	char	**arr;
	int		index;
	int		length;

	if (!lst)
		return (NULL);
	length = ft_lstlen(lst);
	arr = (char**)ft_memalloc(sizeof(char*) * (length + 1));
	arr[length] = NULL;
	index = 0;
	while (index < length)
	{
		arr[index] = ft_strdup(lst->content);
		index++;
		lst = lst->next;
	}
	return (arr);
}
