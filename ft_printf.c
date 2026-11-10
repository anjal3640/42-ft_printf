/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankadava <ankadava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:07:28 by ankadava          #+#    #+#             */
/*   Updated: 2026/11/10 13:19:46 by ankadava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	functionIdentifier(char specifier, va_list *args)
{

	if (specifier == 'c')
		return (ft_putchar_int(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_putstr_int(va_arg(*args, char *)));
	else if (specifier == 'p')
		return (ft_putptr_int(va_arg(*args,void*)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_int(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_putnbr_base_int(va_arg(*args, unsigned int), "0123456789"));
	else if (specifier == 'x')
		return (ft_putnbr_base_int(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_putnbr_base_int(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (specifier == '%')
		return (ft_putchar_int(specifier));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	argument;
	int		len;

	va_start(argument, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format != '\0')
				len += functionIdentifier(*format, &argument);
			else
				return (-1);
		}
		else
			len += ft_putchar_int(*format);
		format++;
	}
	va_end(argument);
	return (len);
}
