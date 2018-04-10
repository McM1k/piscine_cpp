/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:34:39 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 21:34:19 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Window.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Invader.hpp"
#include "BackGroundPelletManager.hpp"

#include <unistd.h>
void wait(unsigned int microseconds)
{
	usleep(microseconds * 1000);
}

bool	isInt(std::string str)
{
	int l = str.length();
	for (int i = 0; i < l; i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

int main(int argc, char const *argv[])
{
	// Loger::log() << "lol\n" << std::flush;
	//(void)argc;
	//(void)argv;
	Window	win;
	win.addEntity(new BackGroundPelletManager());
	// win.getEntityManager().addPlayer(new Player(win));

	int	t = 1;
	if (argc > 1 && isInt(argv[1]))
	{
		std::istringstream	buf(argv[1]);
		buf >> t;
		if (t < 1 || t > 16)
			t = 1;
	}
	for (int i = 0; i < t; i++)
		win.getEntityManager().addPlayer(new Player(win));

	/*Player	*pl = new Player();
	pl->setPos(LINES / 2, COLS / 4 + 4);
	win.getEntityManager().addPlayer(pl);
	pl = new Player();
	pl->setPos(LINES / 2, COLS / 4 - 4);
	win.getEntityManager().addPlayer(pl);*/



	/*if (argc > 1)
		win.getEntityManager().addPlayer(new Player(win, 259, 258, 260, 261, 48));
	if (argc > 2)
		win.getEntityManager().addPlayer(new Player(win, 56, 53, 52, 54, 57));*/

	/*for (int i = 0; i < 50; i++)
		win.getEntityManager().addEnemy(
			new Invader(win.getElapsed() + i, win.getHeigth() / 4, win.getWidth() / 4));*/
	// 	win.addEntity(new Invader(win.getElapsed() + i, LINES / 4, COLS / 4));
	win.start();
	double	nextFrame = win.getElapsed();
	double	nextSpawn = 0.1;
	while (win.run())
	{
		while (nextSpawn < win.getElapsed())
		{
			double tm = win.getElapsed();
			nextSpawn += (tm / (tm + tm)) * 2;
			win.getEntityManager().addEnemy(
				new Invader(win.getElapsed(), -win.getHeigth() / 4, win.getWidth() / 4));
		}
		if (nextFrame < win.getElapsed())
		{
			nextFrame += (1.0 / 30.0);
			win.update();
			win.render();
			// Loger::log() << "time : " << win.getElapsed() << "\n" << std::flush;
		}
		else
			wait(1);
		// wait(1000 / 30);
	}
	return (0);
}
