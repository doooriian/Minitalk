/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:27 by doley             #+#    #+#             */
/*   Updated: 2024/12/07 18:28:28 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	g_confirmation = 0;

static void	send_char(int server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_confirmation == 0)
			;
		g_confirmation = 0;
		bit--;
	}
}

static void	handler_client(int sig)
{
	if (sig == SIGUSR1)
		g_confirmation = 1;
	else
		ft_printf("message receive!\n");
}

static int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Error : wrong format!\n\n"
			"The structure should be like that :\n\n");
		ft_printf("                         ");
		ft_printf("./client <PID> (message)\n\n");
		ft_printf("For example : ./client 1491 HelloWorld\n");
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			ft_printf("Error : not a PID!\n\n");
			ft_printf("A PID must contain only digits\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	int					i;
	struct sigaction 	sa;

	if (!check_input(argc, argv))
		return (1);
	i = 0;
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = handler_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argv[2][i])
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, '\0');
}
