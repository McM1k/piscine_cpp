/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackGroundPelletManager.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:37:21 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/14 16:37:21 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BackGroundPelletManager.hpp"
#include <iostream>

/*
 * Constructors
 */
BackGroundPelletManager::BackGroundPelletManager(void)
{
	for (int i = 0; i < 64; i++)
		_pellet[i] = NULL;
	//std::cout << "An instance of BackGroundPelletManager has been created" << std::endl;
}

BackGroundPelletManager::BackGroundPelletManager(
		BackGroundPelletManager const &src) {
	//std::cout << "An instance of BackGroundPelletManager has been created by copy" << std::endl;
	*this = src;
}

/*
 * Destructors
 */
BackGroundPelletManager::~BackGroundPelletManager(void) {
	//std::cout << "An instance of BackGroundPelletManager has been destroyed" << std::endl;
}

/*
 * Getters
 */

/*
 * Setters
 */

/*
 * Equals
 */
BackGroundPelletManager &
BackGroundPelletManager::operator=(BackGroundPelletManager const &rhs) {
	if (this != &rhs) {
		//this->XXX = rhs.getXXX();
	}
	return *this;
}

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, BackGroundPelletManager const &i) {
	(void)i;
	o << "no attributes" << std::endl;
	return o;
}

/*
 * Other
 */
void BackGroundPelletManager::update(Window &win) {
	static int sp = 0;
	int i;

	if (!(sp++ % 3)){
		i = 0;
		while (this->_pellet[i] != NULL && i < 64)
		{
			i++;
		}
		if (i < 64)
			this->_pellet[i] = new BackGroundPellet(win);
	}

	for (i = 0; i < 64; i++)
	{
		if (this->_pellet[i] != NULL && !this->_pellet[i]->isAlive()) {
			delete this->_pellet[i];
			this->_pellet[i] = NULL;
		}
		else if (this->_pellet[i] != NULL)
			this->_pellet[i]->update(win);

	}
}

void BackGroundPelletManager::render(Window &win) {
	int i = 0;
	while (i < 64) {
		if (this->_pellet[i] != NULL && this->_pellet[i]->isAlive())
			this->_pellet[i]->render(win);
		i++;
	}
}
