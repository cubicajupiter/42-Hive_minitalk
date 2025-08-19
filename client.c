
# include "includes/client.h"
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

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
			return (0);
		}
		string = argv[2];
		if (string[0] == 0)
		{
			write(1, "Faulty message argument.", 24);
			return (0);
		}
		if (signaler(serv_pid, string) == ERROR)
		{
			write(1, "Signaler error: kill() function failure.", 40);
			return (0);
		}
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
			if (send_bit((unsigned char)string[chara], j, serv_pid))
				return (ERROR);
			usleep(50);
			j++;
		}
		chara++;
	}
	if (end_of_message(serv_pid))
		return (ERROR);
	return (0);
}

int		end_of_message(pid_t serv_pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (kill(serv_pid, SIGUSR2))
			return (ERROR);
		usleep(50);
		i++;
	}
	return (0);
}

int		send_bit(unsigned char chara, int j, pid_t serv_pid)
{
	if ((chara >> j) & 1)
	{
		if (kill(serv_pid, SIGUSR1))
			return (ERROR);
	}
	else if ((!(chara >> j) & 1))
	{
		if (kill(serv_pid, SIGUSR2))
			return (ERROR);
	}
	return (0);
}
