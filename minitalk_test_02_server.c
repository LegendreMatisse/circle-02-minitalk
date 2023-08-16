/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_test_02_server.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/08/16 19:53:35 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "printf/ft_printf.h"
#include "libft/libft.h"

void	ft_print_recieved(char *bit_str);

static void	ft_recieve(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;

	(void)info;
	(void)context;
	c = 0;
	i = 0;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			return ;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;

}

int	ft_bin_to_char_2(char *bit_str)
{
	int	i;
	int	c;

	i = 7;
	c = 0;
	while (bit_str[i])
	{
		if (bit_str[i] == '1')
			c |= (1 << (7 - i));
		else
			c |= (0 << (7 - i));
		i--;
	}
	return (c);
}

void	ft_print_recieved(char	*bit_str)
{
	size_t	len;

	len = ft_strlen(bit_str);
	if (len == 8)
		ft_printf("%s", ft_bin_to_char_2(bit_str));
}

int	main(void)
{
	struct sigaction	s_sa;

	ft_printf("The server has started...\n", 1);
	ft_printf("The PID is: %d\n", getpid());
	s_sa.sa_sigaction = ft_recieve;
	s_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sa, 0);
	sigaction(SIGUSR2, &s_sa, 0);
	while (1)
		pause();
	return (0);
}
