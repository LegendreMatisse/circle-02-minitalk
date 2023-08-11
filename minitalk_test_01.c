/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_test_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:37:38 by mlegendr          #+#    #+#             */
/*   Updated: 2023/08/11 17:56:15 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

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

int ft_bin_to_char_calc(char	*bin_str);

void	ft_char_to_bin(char *str)
{
	char	c;
	int		i;
	int		j;
	int		bit_count;
	char	bin_str[9];

	i = 0;
	while (str[i])
	{
		// Char to binary
		j = 0;
		c = str[i];
		printf("%c: ", c);
		bit_count = 8;
		while (bit_count--)
		{
			if (c & 0x80)
				bin_str[j] = '1';
			else
				bin_str[j] = '0';
			c <<= 1;
			j++;
		}
		bin_str[j] = '\0';
		printf("%s", bin_str);

		// Binary to char
		char	converted_c;
		
		converted_c = '\0';
		converted_c = ft_bin_to_char_calc(bin_str);
		printf(" Converted: %c\n", converted_c);
		i++;
	}

}

int	ft_bin_to_char_calc(char *bin_str)
{
	int		result;
	int		int_c;
	int		base;
	int		i;
	int		j;
	int		result_power;

	result = 0;
	int_c = 0;
	base = 2;
	result_power = 0;
	i = 7;
	j = 0;
	while (bin_str[j])
	{
		int_c = bin_str[j] - '0';
		result_power = ft_iterative_power(base, i);
		result += int_c * result_power;
		i--;
		j++;
	}
	return (result);
}

void	ft_bin_conv(int pid, char *str)
{
	char	c;
	int		bit_count;
	int		i;

	(void)pid;
	i = 0;
	while (str[i])
	{
		bit_count = 8;
		(void)bit_count;
		c = str[i++];
		printf("%c\n", c);
		for (int i = 0; i < 8; i++)
			printf("%d", !!((c << i) & 0x80));
		printf("\n");
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signum;
	printf("\n\nSignal handler function called %d\n\n", signum);
	exit(1);
}

int	main(void)
{
	char	str_1[] = "Banaan";
	ft_bin_conv(0, str_1);
	printf("\n\n ~~~~~ \n\n");
	ft_char_to_bin(str_1);

	/*
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGINT, &sa, NULL);
	while (1)
		sleep(1);
	 */
	return (0);
}
