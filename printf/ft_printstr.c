/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:27:27 by mlegendr          #+#    #+#             */
/*   Updated: 2023/05/18 17:38:24 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	printedchars;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	printedchars = 0;
	ft_putstr_fd(str, 1);
	printedchars += ft_strlen(str);
	return (printedchars);
}
