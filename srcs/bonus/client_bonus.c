/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:43 by doley             #+#    #+#             */
/*   Updated: 2024/12/11 18:04:48 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"

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

static void	handle_client(int sig)
{
	if (sig == SIGUSR1)
		g_confirmation = 1;
	else
		ft_printf("\e[32;49;1mmessage receive!\e[0m\n");
}

static void	handle_sigint(int sig)
{
	(void)sig;
	ft_printf("\n\e[31;49;1mClient is shutting down...\e[0m\n");
	exit(0);
}

static int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("\e[31;49;1mError : wrong format!\e[0m\n\n"
			"💡 \e[33;3mThe structure should be like that :\e[0m\n\n");
		ft_printf("                         ");
		ft_printf("./client <PID> (message)\n\n");
		ft_printf("For example : ./client 1491 HelloWorld\n");
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			ft_printf("\e[31;49;1mError : not a PID!\e[0m\n\n");
			ft_printf("💡 \e[33;3mA PID must contain only digits\e[0m\n");
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
	struct sigaction	sa;
	struct sigaction	sa_sigint;

	if (!check_input(argc, argv))
		return (1);
	i = 0;
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = handle_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa_sigint.sa_handler = handle_sigint;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa_sigint, NULL);
	while (argv[2][i])
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, '\0');
}
