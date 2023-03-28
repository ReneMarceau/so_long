/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:44:03 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/28 13:33:55 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return ((int)ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

void	ft_printnbr_base(long nb, char *base, int *length)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb < 0 && base_len <= 10)
	{
		*length += ft_print_char('-');
		nb *= -1;
	}
	if ((size_t)nb >= base_len)
	{
		ft_printnbr_base(nb / base_len, base, length);
		ft_printnbr_base(nb % base_len, base, length);
	}
	else
		*length += ft_print_char(base[nb]);
}
