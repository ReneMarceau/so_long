/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:59:37 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/18 17:38:58 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_formats(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(arg, int));
	else if (format == 's')
		len += ft_print_str(va_arg(arg, char *));
	else if (format == 'p')
	{
		len += ft_print_str("0x");
		ft_printnbr_base(va_arg(arg, unsigned long), "0123456789abcdef", &len);
	}
	else if (format == 'd' || format == 'i')
		ft_printnbr_base(va_arg(arg, int), "0123456789", &len);
	else if (format == 'u')
		ft_printnbr_base(va_arg(arg, unsigned int), "0123456789", &len);
	else if (format == 'x')
		ft_printnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", &len);
	else if (format == 'X')
		ft_printnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", &len);
	else if (format == '%')
		len += ft_print_char('%');
	return (len);
}
