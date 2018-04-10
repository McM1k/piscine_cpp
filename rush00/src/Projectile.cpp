/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:55:43 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 18:34:43 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Projectile.hpp"
#include "Window.hpp"

Projectile::Projectile() :
	_alive(false)
{

}

Projectile::Projectile(float px, float py, float dx, float dy, bool enemy) :
	_px(px), _py(py), _alive(true), _enemy(enemy)
{
	float	len = (dx * dx + dy * dy);
	if (len)
		len = 1.0f / len;
	else
		len = 1.0f;
		_dx = dx * len;
		_dy = dy * len;
}

void Projectile::set(float px, float py, float dx, float dy, bool enemy)
{
	_alive = true;
	_px = px;
	_py = py;
	_dx = dx;
	_dy = dy;
	_enemy = enemy;
	float	len = (dx * dx + dy * dy);
	if (len)
		len = 1.0f / len;
	else
		len = 1.0f;
		_dx = dx * len;
		_dy = dy * len;
}

int Projectile::getX() const
{
	return (this->_px);

}

int Projectile::getY() const
{
	return (this->_py);
}

bool Projectile::isEnemy() const
{
	return (this->_enemy);
}

Projectile::~Projectile()
{

}

Projectile::Projectile(Projectile const &copy)
{
	*this = copy;
}

Projectile &Projectile::operator=(Projectile const &r)
{
	(void)r;
	return (*this);
}

void Projectile::update(Window &win)
{
	(void)win;
	_px += _dx;
	_py += _dy;
	if (_px < 1 || _px >= win.getHeigth() - 2 || _py < 1 || _py * 2 >= win.getWidth())
		_alive = false;
}

void Projectile::render(Window &win)
{
	(void)win;
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	if (_enemy) {
		attrset(COLOR_PAIR(1));
		mvaddch(roundf(_px), roundf(_py * 2), 'v');
	}
	else {
		attrset(COLOR_PAIR(2));
		mvaddch(roundf(_px), roundf(_py * 2), '^');
	}
	attrset(COLOR_PAIR(0));
}

bool Projectile::alive()
{
	return (_alive);
}

void Projectile::destroy()
{
	_alive = false;
}
