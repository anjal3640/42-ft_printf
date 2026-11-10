/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankadava <ankadava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:31:36 by ankadava          #+#    #+#             */
/*   Updated: 2026/11/10 16:28:27 by ankadava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_int(char c);
int	ft_strlen(const char *s);
int	ft_putstr_int(char *s);
int	ft_putnbr_int(int n);
int	ft_putnbr_base_int(unsigned long nbr, char *basestr);
int	ft_putptr_int(void *ptr);

#endif