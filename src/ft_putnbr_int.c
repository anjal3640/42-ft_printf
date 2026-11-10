/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankadava <ankadava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:40:56 by ankadava          #+#    #+#             */
/*   Updated: 2026/11/10 16:30:34 by ankadava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_int(int n)
{
	unsigned int	nbr;
	int				len;

	if (n < 0)
	{
		nbr = n;
		nbr = -nbr;
		len = ft_putchar_int('-');
	}
	else
	{
		nbr = n;
		len = 0;
	}
	len += ft_putnbr_base_int(nbr, "0123456789");
	return (len);
}
