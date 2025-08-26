#ifndef CLIENT_H
# define CLIENT_H

# include "printf/libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

# define ERROR -1

int			main(int argc, char **argv);
int			ft_signaler(pid_t serv_pid, char *string);
int			ft_end_of_message(pid_t serv_pid);
int			ft_send_bit(unsigned char chara, int j, pid_t serv_pid);
void		ft_ack_received(int signum);

#endif
