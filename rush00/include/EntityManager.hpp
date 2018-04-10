/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityManager.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:13:46 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 19:30:09 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYMANAGER_HPP
# define ENTITYMANAGER_HPP

# include <string>
# include "IEntity.hpp"
# include "IEnemy.hpp"
# include "Player.hpp"
# include "Projectile.hpp"

class EntityManager
{
public:
	EntityManager();
	EntityManager(EntityManager const &copy);
	~EntityManager();
	EntityManager &operator=(EntityManager const &rhs);
	int addPlayer(Player *e);
	int addEnemy(IEnemy *e);
	void fire(float px, float py, float dx, float dy, bool enemy);
	void update(Window &win);
	void render(Window &win);
	void renderScore(Window &win, int x, int y, int h, int w);
	void addScore(int score);
protected:
private:
	Player		*_player[16];
	IEnemy		*_enemy[512];
	Projectile	_projectiles[512];
	int _score;
};

#endif
