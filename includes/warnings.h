/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warnings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:27:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 21:40:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARNINGS_H
# define WARNINGS_H

/******************************************************************************\
 * CONTROL
\******************************************************************************/

# define ENVHT_REINIT_WRN "Can't reinitialize envht."
# define ENVHT_REDESTROY_WRN "Can't envht if it's not initialized."

/******************************************************************************\
 * PARSER
\******************************************************************************/

# define DESTROY_PNODE_NULL_WRN "Can't destroy a NULL parser node."

/******************************************************************************\
 * HASH TABLE
\******************************************************************************/

# define DESTROY_NULL_HT_WRN "Can't destroy a NULL hash table."

# define HT_DESTROY_ITEM_NULL_WRN "Can't destroy a NULL hash table item."

#endif
