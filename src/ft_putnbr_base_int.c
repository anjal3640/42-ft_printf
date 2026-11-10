/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankadava <ankadava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:37:50 by ankadava          #+#    #+#             */
/*   Updated: 2026/11/10 16:31:20 by ankadava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_int(unsigned long nbr, char *basestr)
{
	int	len;
	int	base;

	len = 0;
	base = ft_strlen(basestr);
	if (nbr < (unsigned long)base)
	{
		len += ft_putchar_int(basestr[nbr]);
	}
	else
	{
		len += ft_putnbr_base_int(nbr / base, basestr);
		len += ft_putnbr_base_int(nbr % base, basestr);
	}
	return (len);
}
