/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/09/22 16:09:04 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static int				j = 0;
	static unsigned char	c = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - i));
	else if (sig == SIGUSR2)
		c |= (0 << (7 - i));
	i++;
	if (++j == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sa;

	(void)s_sa;
	ft_printf("The server has started...\n");
	ft_printf("The server PID is: %d\n", getpid());
	while (1)
	{
		s_sa.sa_sigaction = &sig_handler;
		s_sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &s_sa, 0);
		sigaction(SIGUSR2, &s_sa, 0);
	}
}
