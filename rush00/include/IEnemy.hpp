/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:31:10 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 16:26:37 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IENEMY_HPP
# define IENEMY_HPP

# include <string>
# include <ncurses.h>
# include "IEntity.hpp"

class Window;

class IEnemy : public IEntity
{
public:
	virtual ~IEnemy() {}
	virtual void update(Window &win) = 0;
	virtual void render(Window &win) = 0;
	virtual bool collide(int x, int y) = 0;
	virtual bool alive() = 0;
protected:
private:

};

#endif
