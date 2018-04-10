/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:31:14 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 21:29:59 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Window.hpp"

int Player::_gid = 0;

Player::Player() :
	_px(LINES / 4 * 3), _py(COLS / 4), _dir(0), _shootCooldown(0), _life(3)
{
	_inputUp = 119;
	_inputDown = 115;
	_inputLeft = 97;
	_inputRight = 100;
	_inputStop = 32;
	_id = _gid++;
}
Player::Player(Window &win) :
	_px(win.getHeigth() / 4 * 3), _py(win.getWidth() / 4), _dir(0), _shootCooldown(0), _life(3)
{
	_inputUp = win.inputKey("key up");
	_inputDown = win.inputKey("key down");
	_inputLeft = win.inputKey("key left");
	_inputRight = win.inputKey("key right");
	_inputStop = win.inputKey("key stop");
	/*_inputUp = 119;
	_inputDown = 115;
	_inputLeft = 97;
	_inputRight = 100;
	_inputStop = 32;*/
	_id = _gid++;
}

Player::Player(Window &win, int up, int down, int left, int right, int stop) :
	_px(win.getHeigth() / 4 * 3), _py(win.getWidth() / 4), _dir(0), _shootCooldown(0), _life(3)
{
	_inputUp = up;
	_inputDown = down;
	_inputLeft = left;
	_inputRight = right;
	_inputStop = stop;
	_id = _gid++;
}

Player::~Player()
{

}

Player::Player(Player const &copy)
{
	*this = copy;
}

Player &Player::operator=(Player const &rhs)
{
	(void)rhs;
	return (*this);
}

void Player::update(Window &win)
{
	const int key = win.getKey();
	if (key == _inputUp)
		_dir = 1;
	else if (key == _inputDown)
		_dir = 2;
	else if (key == _inputLeft)
		_dir = 3;
	else if (key == _inputRight)
		_dir = 4;
	else if (key == _inputStop)
		_dir = 0;
	if (_dir == 1)
	{
		_px--;
		if (_px < 20)
			_px = 20;
	}
	else if (_dir == 2)
	{
		_px++;
		if (_px > win.getHeigth() - 2)
			_px = win.getHeigth() - 2;
	}
	else if (_dir == 3)
	{
		_py--;
		if (_py < 2)
			_py = 2;
	}
	else if (_dir == 4)
	{
		_py++;
		if (_py > win.getWidth() / 2 - 2)
			_py = win.getWidth() / 2 - 2;
	}

	if (!_shootCooldown--)
	{
		_shootCooldown += 10;
		float	rd = (rand() % 100 - 50) * 0.001;
		win.getEntityManager().fire(_px - 1, _py, -1, 0 + rd, false);
		// win.getEntityManager().fire(_px - 1, _py, -1, 0.03 + rd, false);
		// win.getEntityManager().fire(_px - 1, _py, -1, -0.03 + rd, false);
	}
}

void Player::render(Window &win)
{
	(void)win;
	/*const char *ship =
		" /V\ \n"
		"/-P-\";*/
	if (_id == 0)
	{
		init_pair(4, COLOR_GREEN, COLOR_BLACK);
		attrset(COLOR_PAIR(4));
	}
	else if (_id == 1)
	{
		init_pair(5, COLOR_YELLOW, COLOR_BLACK);
		attrset(COLOR_PAIR(5));
	}
	mvaddch(_px - 1, _py * 2, 'V');
	mvaddch(_px - 1, _py * 2 + 1, '\\');
	mvaddch(_px - 1, _py * 2 - 1, '/');
	mvaddch(_px, _py * 2 + 1, '-');
	mvaddch(_px, _py * 2 - 1, '-');
	mvaddch(_px, _py * 2 + 2, '\\');
	mvaddch(_px, _py * 2 - 2, '/');
	const char exa[17] = "0123456789ABCDEF";
	mvaddch(_px, _py * 2, exa[_id]);
	attrset(COLOR_PAIR(0));
}

int Player::getX() const
{
	return (_px);
}

int Player::getY() const
{
	return (_py);
}

int Player::getLife() const
{
	return (_life);
}

int Player::getId() const
{
	return (_id);
}

void Player::setPos(int x, int y)
{
	_px = x;
	_py = y;
}
bool Player::collide(int x, int y)
{
	if ((x == _px - 1 && y == _py) ||
		(y >= _py - 1 && y <= _py + 1  && x == _px))
	{
		_life--;
		return (true);
	}
	return (false);
}
bool Player::alive()
{
	return (_life > 0);
}
