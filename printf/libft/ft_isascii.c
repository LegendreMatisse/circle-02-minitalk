/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:28:18 by mlegendr          #+#    #+#             */
/*   Updated: 2023/01/12 15:24:32 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	else
		return (0);
}
