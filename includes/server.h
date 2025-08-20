#ifndef SERVER_H
# define SERVER_H

# include "printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

# define ERROR -1

int			main(void);
void			ft_signal_handler(int signum);
void			char_to_str(int len, unsigned char chara);
void			putstr_and_free();

#endif
