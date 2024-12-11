/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:57 by doley             #+#    #+#             */
/*   Updated: 2024/12/11 17:15:51 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"

static char	*add_char(char c, char *str)
{
	char	*new_str;
	int		len;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 2));
	if (!new_str)
		return (NULL);
	if (str)
		ft_memcpy(new_str, str, len);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	free(str);
	return (new_str);
}

static void	handle_sigint(int sig)
{
    (void)sig;
    ft_printf("\nServer is shutting down...\n");
    exit(0);
}

static void	handle_server(int sig, siginfo_t *info, void *context)
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

void	ft_print_error(void)
{
	ft_printf("Error : wrong format! "
		"The structure should be like that :\n\n");
	ft_printf("                         ");
	ft_printf("./server\n\n");
	ft_printf("For example : ./server_bonus\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	struct sigaction	sa_sigint;

	(void) argv;
	sa.sa_sigaction = handle_server;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa_sigint.sa_handler = handle_sigint;
    sigemptyset(&sa_sigint.sa_mask);
    sa_sigint.sa_flags = 0;
	if (argc != 1)
	{
		ft_print_error();
		return (0);
	}
	ft_printf("Welcome to Dorian's server !\n");
	ft_printf("My PID is : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa_sigint, NULL);
	while (1)
		pause();
	return (0);
}
