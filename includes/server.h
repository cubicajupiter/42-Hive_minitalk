/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:03:39 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/27 10:03:41 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "printf/libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

# define ERROR -1

int			main(void);
void		ft_signal_handler(int signum, siginfo_t *info, void *context);
void		ft_put(int *char_n, unsigned char *str_buffer);

#endif
