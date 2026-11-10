/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankadava <ankadava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:23:33 by ankadava          #+#    #+#             */
/*   Updated: 2026/11/10 16:31:37 by ankadava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_int(void *ptr)
{
	int	len;

	if (ptr == NULL)
		return (ft_putstr_int("(nil)"));
	else
	{
		len = ft_putstr_int("0x");
		len += ft_putnbr_base_int((unsigned long)ptr, "0123456789abcdef");
	}
	return (len);
}
