/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_test_02_server.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/08/22 16:28:06 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "printf/ft_printf.h"
#include "libft/libft.h"

static void	ft_test_server(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static int				j = 0;
	static unsigned char	c = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_putchar_fd('1', 1);
		c |= (1 << (7 - i));
	}
	else if (sig == SIGUSR2)
	{
		ft_putchar_fd('0', 1);
		c |= (0 << (7 - i));
	}
	i++;
	if (++j == 8)
	{
		ft_putstr_fd("c: ", 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
		c = 0;
		i = 0;
		j = 0;
	}

}

int	main(void)
{
	struct sigaction	s_sa;

	ft_printf("The server has started...\n");
	ft_printf("The server PID is: %d\n", getpid());
	s_sa.sa_sigaction = ft_test_server;
	s_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sa, 0);
	sigaction(SIGUSR2, &s_sa, 0);
	while (1)
		pause();
	return (0);
}
