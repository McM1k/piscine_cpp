/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackGroundPelletManager.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:34:20 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/14 16:34:20 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUNDPELLETMANAGER_HPP
# define BACKGROUNDPELLETMANAGER_HPP
# include "BackGroundPellet.hpp"
#include "IEntity.hpp"
# include <iostream>

class BackGroundPelletManager : public IEntity{
public:
	BackGroundPelletManager(void);
	BackGroundPelletManager(BackGroundPelletManager const &src);
	virtual ~BackGroundPelletManager(void);
	BackGroundPelletManager &operator=(BackGroundPelletManager const &rhs); //equals
	void update(Window &win);
	void render(Window &win);

private:
	 BackGroundPellet *_pellet[64];

};

std::ostream &operator<<(std::ostream &o, BackGroundPelletManager const &i);

#endif