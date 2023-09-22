/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/09/22 15:19:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"
*/
#include "minitalk.h"

void	ft_test_client(int pid, char *str)
{
	unsigned char	c;
	int				i;
	int				bit_count;
	int				msb_value;

	i = 0;
	while (str[i])
	{
		bit_count = 8;
		c = str[i];
		i++;
		while (bit_count--)
		{
			msb_value = 0;
			msb_value = (c >> bit_count) & 1;
			if (msb_value == 1)
				kill(pid, SIGUSR1);
			else if (msb_value == 0)
				kill(pid, SIGUSR2);
			usleep(500);
		}
	}
	bit_count = 8;
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("This is not the correct input.\n");
		ft_printf("Try: ./client <server pid> <string to send>\n");
		return (1);
	}
	ft_test_client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
