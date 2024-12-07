/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:47 by doley             #+#    #+#             */
/*   Updated: 2024/12/07 18:35:38 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static char	*add_char(char c, char *str)
{
	int		i;

	i = 0;
	if (!str)
		str = malloc(sizeof(char) + 1);
	return (ft_strjoin(str, &c));
}

static void	handler_server(int sig, siginfo_t *info, void *context)
{
	static int	bit = 7;
	static char	c = 0;
	static char	*str = NULL;

	(void) context;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0)
	{
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			kill(info->si_pid, SIGUSR2);
			free(str);
			str = NULL;
		}
		else
			str = add_char(c, str);
		bit = 7;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void) argv;
	sa.sa_sigaction = handler_server;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		ft_printf("Error : wrong format! "
			"The structure should be like that :\n\n");
		ft_printf("                         ");
		ft_printf("./server\n\n");
		ft_printf("For example : ./server_bonus\n");
		return (0);
	}
	ft_printf("Welcome to Dorian's server !\n");
	ft_printf("My PID is : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
