/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_test_02_client.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/08/18 19:13:23 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

static void	action(int sig)
{
	static int	recieved = 0;

	if (sig == SIGUSR1)
		++recieved;
	else
	{
		ft_printf("%d\n", recieved);
		exit(0);
	}
}

void	ft_test(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
//	ft_char_to_bin(ft_atoi(argv[1]), argv[2]);
//	ft_test(ft_atoi(argv[1]), argv[2]);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	ft_test(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
