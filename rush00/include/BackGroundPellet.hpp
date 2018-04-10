/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackGroundPellet.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:19:43 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/14 11:19:43 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUNDPELLET_HPP
# define BACKGROUNDPELLET_HPP
# include "IEntity.hpp"
# include <iostream>

class BackGroundPellet : public IEntity
{
public:
	BackGroundPellet(void);
	virtual ~BackGroundPellet(void);
	BackGroundPellet(Window &win);
	void update(Window &win);
	void render(Window &win);
	bool isAlive();

private:
	float	_pos_x;
	float 	_pos_y;
	float	_speed;
	bool	_alive;

	BackGroundPellet &operator=(BackGroundPellet const &rhs); //equals
	BackGroundPellet(BackGroundPellet const &src);

};

std::ostream &operator<<(std::ostream &o, BackGroundPellet const &i);


#endif