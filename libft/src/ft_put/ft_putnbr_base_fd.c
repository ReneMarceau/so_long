/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:03:38 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/18 17:41:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr_base_fd(int nb, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
	}
	if ((size_t)nb >= base_len)
	{
		ft_putnbr_base_fd(nb / base_len, base, fd);
		ft_putnbr_base_fd(nb % base_len, base, fd);
	}
	else
		ft_putchar_fd(base[nb], fd);
}
