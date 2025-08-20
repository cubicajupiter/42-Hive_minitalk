
# include "includes/client.h"

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
		signaler(serv_pid, string);
	}
	return (0);
}

int		signaler(pid_t serv_pid, char *string)
{
	int		chara;
	int		j;

	chara = 0;
	while (string[chara])
	{
		j = 0;
		while (j < 8)
		{
			send_bit((unsigned char)string[chara], j, serv_pid);
			usleep(50);
			j++;
		}
		chara++;
	}
	end_of_message(serv_pid);
	return (0);
}

int		end_of_message(pid_t serv_pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		kill(serv_pid, SIGUSR2);
		usleep(50);
		i++;
	}
	return (0);
}

int		send_bit(unsigned char chara, int j, pid_t serv_pid)
{
	if ((chara >> j) & 1) //1
	{
		if (kill(serv_pid, 0))
			ft_printf("Process %d does not exist, or PID is wrong.", serv_pid);
		else
			kill(serv_pid, SIGUSR1);
			
	}
	else if (!((chara >> j) & 1)) //0
	{
		if (kill(serv_pid, 0))
			ft_printf("Process %d does not exist, or PID is wrong.", serv_pid);
		else
			kill(serv_pid, SIGUSR2);
	}
	return (0);
}
