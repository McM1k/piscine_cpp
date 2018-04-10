/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:31:12 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 17:54:59 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include "IEntity.hpp"

class Window;

class Player : public IEntity
{
public:
	Player();
	Player(Window &win);
	Player(Window &win, int up, int down, int left, int right, int stop);
	Player(Player const &copy);
	virtual ~Player();
	Player &operator=(Player const &rhs);
	virtual void update(Window &win);
	virtual void render(Window &win);
	int getX() const;
	int getY() const;
	int getLife() const;
	int getId() const;
	void setPos(int x, int y);
	bool collide(int x, int y);
	bool alive();
protected:
private:
	int	_px;
	int	_py;
	int	_inputUp;
	int	_inputDown;
	int	_inputLeft;
	int	_inputRight;
	int	_inputStop;
	int _dir;
	int _shootCooldown;
	int _life;
	int _id;
	static int _gid;
};

#endif
