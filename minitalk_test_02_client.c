/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_test_02_client.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/08/16 19:46:01 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_char_to_bin(int pid, char *str)
{
	char	c;
	int		i;
	int		j;
	int		bit_count;

	i = 0;
	while (str[i])
	{
		// Char to binary
		j = 0;
		c = str[i];
		bit_count = 8;
		while (bit_count--)
		{
			if (c & 0x80)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			c <<= 1;
			j++;
		}
		i++;
	}

}

int	main(int argc, char **argv)
{
	(void)argc;
	ft_char_to_bin(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
