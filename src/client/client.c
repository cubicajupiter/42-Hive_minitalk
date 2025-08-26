
# include "client.h"

int		g_acknowledged;

int	main(int argc, char **argv)
{
	pid_t	serv_pid;
	char	*string;

	if (argc == 3)
	{
		serv_pid = (pid_t) ft_atoi(argv[1]);
		if (!serv_pid)
		{
			write(1, "Faulty Process ID argument.", 27);
			return (ERROR);
		}
		string = argv[2];
		if (string[0] == 0)
		{
			write(1, "Faulty message argument.", 24);
			return (ERROR);
		}
		if (ft_signaler(serv_pid, string))
			return (ERROR);
	}
	return (0);
}

int		ft_signaler(pid_t serv_pid, char *string)
{
	int					chara;
	int					j;
	struct sigaction	ack_handler;

	ack_handler.sa_handler = ft_ack_received;
	ack_handler.sa_flags = 0;
	sigemptyset(&ack_handler.sa_mask);
	sigaction(SIGUSR1, &ack_handler, NULL);
	chara = 0;
	while (string[chara])
	{
		j = 0;
		while (j < 8)
		{
			if (ft_send_bit((unsigned char)string[chara], j, serv_pid))
				return (ERROR);
			while (!g_acknowledged)
				;
			j++;
		}
		chara++;
	}
	if (ft_end_of_message(serv_pid))
		return (ERROR);
	return (0);
}

int		ft_end_of_message(pid_t serv_pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (kill(serv_pid, 0))
		{
			ft_printf("Process %d does not exist, PID is wrong, or no permission.\n", serv_pid);
			return (ERROR);
		}
		g_acknowledged = 0;
		kill(serv_pid, SIGUSR2);
		while (!g_acknowledged)
			;
		i++;
	}
	return (0);
}

int		ft_send_bit(unsigned char chara, int j, pid_t serv_pid)
{
	g_acknowledged = 0;
	if ((chara >> j) & 1) //1
	{
		if (kill(serv_pid, 0))
		{
			ft_printf("Process %d does not exist, PID is wrong, or no permission.\n", serv_pid);
			return (ERROR);
		}
		kill(serv_pid, SIGUSR1);
	}
	else if (!((chara >> j) & 1)) //0
	{
		if (kill(serv_pid, 0))
		{
			ft_printf("Process %d does not exist, PID is wrong, or no permission.\n", serv_pid);
			return (ERROR);
		}
		kill(serv_pid, SIGUSR2);
	}
	return (0);
}

void	ft_ack_received(int signum)
{
	(void) signum;
	g_acknowledged = 1;
}
