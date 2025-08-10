#ifndef MINIHEADER_H
# define MINIHEADER_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

# define ERROR -1

void			ft_signal_handler(int signum);
void			char_to_str(int len, unsigned char chara);
void			putstr_and_free();
int				signaler(pid_t serv_pid, char *string)
int				end_of_message(pid_t serv_pid)
int				send_bit(unsigned char chara, int j)

#endif
