#ifndef CLIENT_H
# define CLIENT_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

# define ERROR -1

int			main(int argc, char **argv);
int			signaler(pid_t serv_pid, char *string);
int			end_of_message(pid_t serv_pid);
int			send_bit(unsigned char chara, int j, pid_t serv_pid);

#endif
