/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:27:57 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/18 17:42:02 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		while ((haystack[i + j] == needle[j] && haystack[i + j] != '\0')
			&& len > 0)
		{
			len--;
			j++;
		}
		len += j;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		len--;
		i++;
		j = 0;
	}
	return (NULL);
}
