/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:51:04 by myerturk          #+#    #+#             */
/*   Updated: 2024/01/09 16:30:06 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_int(int w);
int	ft_check(char str);
int	ft_putchar(char x);
int	ft_string(char *str);
int	ft_unsigned(unsigned int w);
int	ft_hex(unsigned int d, char w);
int	ft_point(unsigned long w, int i);
int	ft_format(va_list *args, char w);
int	ft_printf(const char *format, ...);

#endif
