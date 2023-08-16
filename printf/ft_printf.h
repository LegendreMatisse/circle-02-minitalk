/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:03:52 by mlegendr          #+#    #+#             */
/*   Updated: 2023/05/18 17:34:59 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

void	ft_hexconvert(unsigned long num, char x);
int		ft_printhex(unsigned long num, char x);
void	ft_putptr(uintptr_t ptr);
int		ft_printptr(unsigned long long ptr);
char	*ft_uitoa(unsigned int num);
int		ft_print_uitoa(unsigned int num);
int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int num);

#endif
