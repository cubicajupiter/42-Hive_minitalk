
# include "includes/server.h"

int	main(void)
{
	struct sigaction	handler;

	ft_printf("Server's PID: %d\n", getpid());
	handler.sa_handler = ft_signal_handler;
	handler.sa_flags = SA_RESTART;
	if (sigemptyset(&handler.sa_mask) == -1)
		return (ERROR);
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	while (1)
		pause();
	return (0);
}

void	ft_signal_handler(int signum)
{
	static unsigned char	built_chara;
	static int				n_bit;

	if (signum == SIGUSR1)
		built_chara |= (1 << n_bit); // 1
	else if (signum == SIGUSR2)
		built_chara &= ~(1 << n_bit); // 0
	n_bit++;
	if (n_bit == 8)
	{
		if (built_chara)
			write(1, &built_chara, 1);
		else
			write(1, "\n", 1);
		n_bit = 0;
		built_chara = 0;
	}
}
