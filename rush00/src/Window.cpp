/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:37:16 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 20:30:52 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Window.hpp"

std::string Window::input(std::string str)
{
	echo();
	nodelay(stdscr, false);
	curs_set(1);

	// std::cout << str << std::endl;
	mvprintw(LINES / 2 - 1, COLS / 2 - str.length() / 2, str.c_str());
	move(LINES / 2, COLS / 2 - str.length() / 2);
	std::string out;
	char buf[256];
	getstr(buf);
	out = buf;
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	return (out);
}

int Window::inputKey(std::string str)
{
	echo();
	nodelay(stdscr, false);
	curs_set(1);

	// std::cout << str << std::endl;
	mvprintw(LINES / 2 - 1, COLS / 2 - str.length() / 2, str.c_str());
	move(LINES / 2, COLS / 2 - str.length() / 2);
	int k = getch();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	return (k);
}

Window::Window()
{
	_run = true;
	for (int i = 0; i < 128; i++)
		_entity[i] = NULL;
	initscr();				/* Start curses mode 		*/
	start_color();
	raw();					/* Line buffering disabled	*/
	keypad(stdscr, true);	/* We get F1, F2 etc..		*/
	noecho();				/* Don't echo() while we do getch */
	curs_set(0);


	// timeout(1000);



	// move(1, 1);

	// nodelay(stdscr, true);
	// meta(stdscr, true);

	if (COLS < 140)
	{
		Loger::log() << "window width to small: " << COLS << "/100\n";
		_run = false;
	}
	if (LINES < 50)
	{
		Loger::log() << "window height to small: " << LINES << "/50\n";
		_run = false;
	}
	_height = LINES;
	_width = 100;

	// Loger::log() << "window height to small: " << LINES << "/50\n";
	// Loger::log() << "test : " << input("test input") << std::endl << std::flush;


    // printw("Le terminal actuel comporte %d lignes et %d colonnes\n", LINES, COLS);
    //mvaddch(LINES - 1, COLS - 1, '.');
    //mvprintw(LINES - 1, COLS - 1, ".");
    // printw("Hello World");
	// move(LINES - 1, COLS - 1);
    // addch('.');
	gettimeofday(&_tvStart, 0);
}

Window::~Window()
{
	echo();
	nodelay(stdscr, false);
	curs_set(1);
	noraw();
	endwin();
}

Window::Window(Window const &copy)
{
	*this = copy;
}

Window &Window::operator=(Window const &rhs)
{
	(void)rhs;
	return (*this);
}

int Window::addEntity(IEntity *entity)
{
	if (!entity)
		return (-1);
	for (int i = 0; i < 128; i++)
		if (!_entity[i])
		{
			_entity[i] = entity;
			return (i);
		}
	return (-1);
}

EntityManager &Window::getEntityManager(void)
{
	return (_entityMana);
}

void Window::update()
{
	static int ok = -1;
	int ch;

	while ((ch = getch()) != -1)
	{
		if (ch == 3 || ch == 410 || ch == 27)
		{
			this->_run = false;
			return ;
		}
		if (ch != ok)
		{
			ok = ch;
			break;
		}
	}
	if (ok != -1)
		Loger::log() << "key : " << ok << std::endl << std::flush;
	this->_key = ok;

	_entityMana.update(*this);
	for (int i = 0; i < 128; i++)
	{
		if (_entity[i])
			_entity[i]->update(*this);
	}
}

void Window::render()
{
	std::string	clr;
	std::string	tb;
	tb.resize(COLS, ' ');
	for (int i = 0; i < LINES; i++)
	{
		clr += tb + '\n';
	}
	mvprintw(0, 0, clr.c_str());
	// clear();
	// Loger::log() << "win render\n" << std::flush;









	for (int i = 0; i < 128; i++)
	{
		if (_entity[i])
			_entity[i]->render(*this);
	}
	_entityMana.render(*this);
	for (int i = 0; i < _width + 40; i++)
	{
		mvaddch(0, i, '#');
		mvaddch(_height - 1, i, '#');
	}
	for (int i = 1; i < _height - 1; i++)
	{
		mvaddch(i, _width + 39, '#');
		mvaddch(i, _width - 1, '#');
		mvaddch(i, 0, '#');
	}
	_entityMana.renderScore(*this, 2, _width + 2, _height - 4, 36);
	refresh();
}

int Window::getKey()
{
	return (this->_key);
}

void Window::start()
{
	gettimeofday(&_tvStart, 0);
	_run = true;
}

bool Window::run() const
{
	return (this->_run);
}

void Window::stop()
{
	this->_run = false;
}

double Window::getElapsed()
{
	gettimeofday(&_tv, 0);

	return (_tv.tv_sec - _tvStart.tv_sec + (_tv.tv_usec - _tvStart.tv_usec) / 1000000.0);
}

int Window::getHeigth()
{
	return (_height);
}

int Window::getWidth()
{
	return (_width);
}

// Single-player
// • Display using the ncurses library
// • Horizontal or vertical scrolling (The screen area moves through the world, very
// much like in R-Type for example) // vertical scrolling
// • Random enemies
// • The player can shoot at enemies
// • Basic collision handling (If an enemy touches you, you die)
// • Game entities occupy one ’square’ of the map only.
// • Frame-based timing
// Acquire input (Player controls, network, etc ...)
// • Update game entities
// • Render display
// • Repeat until game ends !
// Displaying score, time, number of lives, etc... on screen
// • Clock-based timing (Use whichever system facility or library you like)
// • Entities that can occupy multiple squares
// • Enemies can also shoot
// • Scenery (Collidable objects or simple background)
// Large and hard-to-beat boss enemies
// • Enemies have a scripted behaviour
// • Multiplayer, either on the same keyboard or through the network if you’re feeling
// cocky
// • Scripted game worlds, with pre-determined batches of enemies
