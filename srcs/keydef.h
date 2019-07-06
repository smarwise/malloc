/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:46:36 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/05 22:58:23 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYDEF_H
# define KEYDEF_H

# if __APPLE__
# define A			0
# define S			1
# define D			2
# define W			13
# define ESC		53
# define ARROWUP	126
# define ARROWDOWN	125
# define NUMDOWN	84
# define NUMLEFT	86
# define NUMRIGHT	88
# define NUM_7		89
# define NUM_5		87
# define NUM_9		92
# define NUMUP		91
# define MOUSETOG	46
# define SPEEDINC	34
# define SPEEDDEC	31
# define VIEWTOG	9

# elif __linux__
# define A			'a'
# define S			's'
# define D			'd'
# define W			'w'
# define ESC		0xff1b
# define ARROWUP	0xff52
# define ARROWDOWN	0xff54
# define NUMDOWN	0xff99
# define NUMLEFT	0xff96
# define NUMRIGHT	0xff98
# define NUM_7		0xff95
# define NUM_5		0xff9d
# define NUM_9		0xff9a
# define NUMUP		0xff97
# define MOUSETOG	'm'
# define SPEEDINC	'i'
# define SPEEDDEC	'o'
# define VIEWTOG	'v'
#endif
#endif