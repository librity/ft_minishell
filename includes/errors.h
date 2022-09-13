/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:27:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 13:04:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_GENERIC "Error"

/******************************************************************************\
 * CONTROL
\******************************************************************************/

# define ENVP_TO_ENVHT_ERR "Can't initialize envht from envp variables."

/******************************************************************************\
 * EXECUTOR
\******************************************************************************/

# define FORK_ERR "Can't fork required process."
# define PATHS_ERR "Can't get paths from environment variable."
# define EXECUTE_NULL_ERR "Can't execute NULL tokens."
# define NO_CMD_ERR "command not found"

/******************************************************************************\
 * FILES
\******************************************************************************/

# define CLOSE_ERR "Can't close required file descriptor."

/******************************************************************************\
 * PIPES
\******************************************************************************/

# define PIPE_ERR "Can't create required pipe."

#endif
