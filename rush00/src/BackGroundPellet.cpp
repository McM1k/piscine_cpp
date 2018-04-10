/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackGroundPellet.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:19:41 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/14 11:19:41 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BackGroundPellet.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Window.hpp"
#include "Loger.hpp"
#include <ncurses.h>

/*
 * Coplien
 */
BackGroundPellet::BackGroundPellet() {

}

BackGroundPellet::BackGroundPellet(Window &win) :
		_pos_x(1),
		_pos_y(rand() % (win.getWidth() - 2) + 1),
		_speed(((float)(rand() % 50) * 0.01) + 0.1),
		_alive(true)
{
	//Loger::log() << "pos : " << _pos_x <<" " << _pos_y << std::endl;

	//std::cout << "An instance of BackGroundPellet has been created" << std::endl;
}

BackGroundPellet::BackGroundPellet(BackGroundPellet const &src)
{
	//std::cout << "An instance of BackGroundPellet has been created by copy" << std::endl;
	*this = src;
}

BackGroundPellet::~BackGroundPellet(void)
{

	//std::cout << "An instance of BackGroundPellet has been destroyed" << std::endl;
}

BackGroundPellet &BackGroundPellet::operator=(BackGroundPellet const &rhs)
{
	(void)rhs;
	return *this;
}

/*
 * Constructors
 */

/*
 * Getters
 */
bool BackGroundPellet::isAlive() {
	return this->_alive;
}

/*
 * Setters
 */

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, BackGroundPellet const &i)
{
	(void)i;
	o << "no attributes" << std::endl;
	return o;
}

/*
 * Other
 */
void BackGroundPellet::render(Window &win)
{
	//Loger::log() << "pos : " << _pos_x <<" " << _pos_y << std::endl;
	//init_pair(1, COLOR_BLUE, COLOR_BLACK);
	//attrset(COLOR_PAIR(1));
	mvaddch(_pos_x, _pos_y, '.');
	//attrset(COLOR_PAIR(0));
	(void)win;
}

void BackGroundPellet::update(Window &win)
{
	//Loger::log() << "pos : " << _pos_x <<" " << _pos_y << std::endl;
	this->_pos_x += this->_speed;
	if (this->_pos_x > win.getHeigth() - 1)
		this->_alive = false;
	(void)win;
}