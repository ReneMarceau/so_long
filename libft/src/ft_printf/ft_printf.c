/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:51:14 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/18 17:39:09 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		total_len;
	va_list	arg;

	i = 0;
	total_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			total_len += ft_formats(arg, str[i + 1]);
			i++;
		}
		else
			total_len += ft_print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (total_len);
}
