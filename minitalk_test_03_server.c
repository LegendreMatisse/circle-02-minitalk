/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_test_03_server.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/08/18 19:12:28 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "printf/ft_printf.h"
#include "libft/libft.h"

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;
	int	k;

	i = power;
	j = 1;
	k = nb;
	if (i < 0)
		return (0);
	if (i == 0)
		return (1);
	while (j < i)
	{
		k = k * nb;
		j++;
	}
	return (k);
}

int	ft_bin_to_char_calc(char *bin_str)
{
	int		result;
	int		int_c;
	int		i;
	int		j;

	result = 0;
	int_c = 0;
	i = 7;
	j = 0;
	while (bin_str[j])
	{
		int_c = bin_str[j] - '0';
		result += int_c * ft_iterative_power(2, i);
		i--;
		j++;
	}
	return (result);
}

static void ft_test_server(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	static unsigned char	c = 0;
	static int				i = 0;

	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

/*
static void ft_test_server(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	int			j;
	static char	bin_str[9];
//	static int	c = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		bin_str[i] = '1';
		i++;
	}
	else if (sig == SIGUSR2)
	{
		bin_str[i] = '0';
		i++;
	}
	if (i == 8)
	{
//		c = ft_bin_to_char_calc(bin_str);
//		ft_printf("%s: %c\n", bin_str, c);
//		c = 0;
		bin_str[i] = '\0';
		ft_printf("%s\n", bin_str);
		i = 0;
		j = -1;
		while (bin_str[++j])
			bin_str[j] = '\0';
	}
}
*/
int	main(void)
{
	struct sigaction	s_sa;

	ft_printf("The server has started...\n", 1);
	ft_printf("The PID is: %d\n", getpid());
//	s_sa.sa_sigaction = ft_recieve;
	ft_printf("\n");
	s_sa.sa_sigaction = ft_test_server;
	s_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sa, 0);
	sigaction(SIGUSR2, &s_sa, 0);
	ft_printf("\n");
	while (1)
		pause();
	return (0);
}
