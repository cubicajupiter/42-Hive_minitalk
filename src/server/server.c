
# include "server.h"

int	main(void)
{
	struct sigaction	handler;

	ft_printf("Server's PID: %d\n", getpid());
	handler.sa_sigaction = ft_signal_handler;
	handler.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigemptyset(&handler.sa_mask) == -1)
		return (ERROR);
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	while (1)
		pause();
	return (0);
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char		built_char;
	static int					bit_n;

	(void) context;
	if (signum == SIGUSR1)
		built_char |= (1 << bit_n);
	else if (signum == SIGUSR2)
		built_char &= ~(1 << bit_n);
	bit_n++;
	if (bit_n == 8)
	{
		bit_n = 0;
		if (built_char)
			write(1, &built_char, 1);
		else
			write(1, "\n", 1);
		built_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
