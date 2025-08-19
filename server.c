char		*g_result_str;

int	main()
{
	struct sigaction	handler;

	ft_printf("Server's PID: %d", getpid());
	handler.sa_handler = ft_signal_handler;
	while (1)
	{
		pause();
		if (sigemptyset(&handler.sa_mask) == -1)
			return (ERROR);
		if (sigaction(SIGUSR1, &handler, NULL) == -1)
			return (ERROR);
		if (sigaction(SIGUSR2, &handler, NULL) == -1)
			return (ERROR);
	}
}

void	ft_signal_handler(int signum)
{
	static unsigned char	built_chara;
	static int		n_bit;
	static int		str_len;

	if (signum == SIGUSR1)
		built_chara |= (1 << n_bit); // 1
	else if (signum == SIGUSR2)
		built_chara &= ~(1 << n_bit); // 0
	n_bit++;
	if (n_bit == 8)
	{
		str_len++;
		if (built_chara)
			char_to_str(str, str_len, built_chara);
		else
		{
			putstr_and_free();
			str_len = 0;
		}
		n_bit = 0;
		built_chara = 0;
	}
}

void	char_to_str(int len, unsigned char chara)
{
	int	i;
	char	*new_str;
	char	*old_str;

	i = 0;
	new_str = malloc(len * sizeof(char));
	old_str = result_str;
	while (i < len && old_str)
	{
		new_str[i] = old_str[i];
		i++;	
	}
	new_str[i++] = chara;
	new_str[i] = '\0';
	g_result_str = new_str;
	free(old_str);
}

void	putstr_and_free()
{
	ft_printf("%s", result_str);
	free(result_str);
	result_str = NULL;
}
