/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:37:18 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 20:14:11 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <string>
# include <ncurses.h>
# include <sys/time.h>
# include "IEntity.hpp"
# include "EntityManager.hpp"

class Window
{
public:
	Window();
	Window(Window const &copy);
	~Window();
	Window &operator=(Window const &rhs);
	int addEntity(IEntity *entity);
	EntityManager &getEntityManager();
	std::string input(std::string str);
	int inputKey(std::string str);
	void update();
	void render();
	int getKey();
	void start();
	bool run() const;
	void stop();
	double getElapsed();
	int getHeigth();
	int getWidth();
protected:
private:
	IEntity *_entity[128];
	EntityManager _entityMana;
	int _key;
	bool _run;
	struct timeval _tvStart;
	struct timeval _tv;
	int _height;
	int _width;
};

#endif
