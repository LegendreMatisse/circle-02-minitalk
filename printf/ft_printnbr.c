/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:43:45 by mlegendr          #+#    #+#             */
/*   Updated: 2023/05/17 19:19:16 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printnbr(int num)
{
	int		printedchars;
	char	*c_num;

	printedchars = 0;
	c_num = ft_itoa(num);
	printedchars = ft_printstr(c_num);
	free(c_num);
	c_num = NULL;
	return (printedchars);
}	
