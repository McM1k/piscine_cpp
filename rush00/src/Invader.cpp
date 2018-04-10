#include <iostream>
#include <cmath>
#include "Window.hpp"
#include "Invader.hpp"

Invader::Invader() : _alive(false)
{

}

Invader::Invader(double time, int x, int y) :
	_px(x), _py(y), _creatTime(time + rand()), _alive(true), _lastMove(0)
{

}

Invader::~Invader()
{

}

Invader::Invader(Invader const &copy)
{
	*this = copy;
}

Invader &Invader::operator=(Invader const &rhs)
{
	(void)rhs;
	return (*this);
}

void Invader::update(Window &win)
{
	if (_lastMove++ >= 8)
	{
		_lastMove = 0;
		_px++;
	}
	double tm = (win.getElapsed() - _creatTime) * 0.2;
	_rx = _px + (win.getHeigth() * 0.20 * sin(tm * 0.18003));
	_ry = _py + ((win.getWidth() * 0.25 - 2) * cos(tm * 0.25));
	static int fire = 0;
	if (!(fire++ % 49))
	{
		float	rd = (rand() % 100 - 50) * 0.001;
		win.getEntityManager().fire(_rx + 1, _ry, 1, 0 + rd, true);
	}
	if (_rx > win.getHeigth())
	{
		_alive = false;
		win.getEntityManager().addScore(-1100);
	}
}

void Invader::render(Window &win)
{
	(void)win;
	/*
		3.6230998 * sin(z * 0.18003);
		2.4324 * cos(z * 0.25);
	*/
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	attrset(COLOR_PAIR(3));
	mvaddch(_rx, _ry * 2, 'X');
	mvaddch(_rx + 1, _ry * 2, 'X');
	mvaddch(_rx - 1, _ry * 2, 'X');
	mvaddch(_rx, _ry * 2 + 1, 'X');
	mvaddch(_rx, _ry * 2 - 1, 'X');
	mvaddch(_rx + 1, _ry * 2 + 1, '/');
	mvaddch(_rx - 1, _ry * 2 + 1, '\\');
	mvaddch(_rx + 1, _ry * 2 - 1, '\\');
	mvaddch(_rx - 1, _ry * 2 - 1, '/');
	attrset(COLOR_PAIR(0));
	// mvaddch(roundf(_px), roundf(_py * 2), 'I');
}

bool Invader::collide(int x, int y)
{
	if ((x >= _rx - 1 && x <= _rx + 1  && y == _ry) ||
		(y >= _ry - 1 && y <= _ry + 1  && x == _rx))
	{
		_alive = false;
		return (true);
	}
	return (false);
}

bool Invader::alive()
{
	return (_alive);
}
