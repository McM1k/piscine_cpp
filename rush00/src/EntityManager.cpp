#include <iostream>
#include <sstream>
#include "EntityManager.hpp"
#include "Window.hpp"

EntityManager::EntityManager() : _score(0)
{
	for (int i = 0; i < 16; i++)
		_player[i] = NULL;
	for (int i = 0; i < 512; i++)
		_enemy[i] = NULL;
}

EntityManager::~EntityManager()
{

}

EntityManager::EntityManager(EntityManager const &copy)
{
	*this = copy;
}

EntityManager &EntityManager::operator=(EntityManager const &rhs)
{
	(void)rhs;
	return (*this);
}
int EntityManager::addPlayer(Player *e)
{
	if (!e)
		return (-1);
	for (int i = 0; i < 16; i++)
		if (!_player[i])
		{
			_player[i] = e;
			return (i);
		}
	return (-1);
}

int EntityManager::addEnemy(IEnemy *e)
{
	if (!e)
		return (-1);
	for (int i = 0; i < 512; i++)
		if (!_enemy[i])
		{
			_enemy[i] = e;
			return (i);
		}
	return (-1);
}

void EntityManager::fire(float px, float py, float dx, float dy, bool enemy)
{
	for (int i = 0; i < 512; i++)
		if (!_projectiles[i].alive())
		{
			_projectiles[i].set(px, py, dx, dy, enemy);
			return ;
		}
}

void EntityManager::update(Window &win)
{
	bool	alive = false;

	for (int i = 0; i < 16; i++)
		if (_player[i] && _player[i]->alive())
		{
			alive = true;
			_player[i]->update(win);
		}
	if (!alive)
	{
		std::stringstream out;
		out << "GAME OVER : ";
		out << _score;
		win.input(out.str());
		win.stop();
		//TODO end
	}
	for (int i = 0; i < 512; i++)
		if (_enemy[i])
		{
			if (!_enemy[i]->alive())
			{
				delete _enemy[i];
				_enemy[i] = NULL;
				_score += 100;
			}
			else
				_enemy[i]->update(win);
		}
	for (int i = 0; i < 512; i++)
		if (_projectiles[i].alive())
			_projectiles[i].update(win);


	// colide
	for (int i = 0; i < 512; i++)
		if (_projectiles[i].alive())
		{
			if (!_projectiles[i].isEnemy())
			{
				for (int j = 0; j < 512; j++)
					if (_enemy[j] && _enemy[j]->collide(
						_projectiles[i].getX(), _projectiles[i].getY()))
					{
						_projectiles[i].destroy();
					}
			}
			else
			{
				for (int j = 0; j < 16; j++)
					if (_player[j] && _player[j]->alive() && _player[j]->collide(
						_projectiles[i].getX(), _projectiles[i].getY()))
					{
						// delete _player[j];
						// _player[j] = NULL;
						_projectiles[i].destroy();
					}
			}
		}
}

void EntityManager::render(Window &win)
{
	for (int i = 0; i < 512; i++)
		if (_projectiles[i].alive())
			_projectiles[i].render(win);
	for (int i = 0; i < 16; i++)
		if (_player[i] && _player[i]->alive())
			_player[i]->render(win);
	for (int i = 0; i < 512; i++)
		if (_enemy[i])
			_enemy[i]->render(win);
}

void EntityManager::renderScore(Window &win, int x, int y, int h, int w)
{
	(void)h;
	(void)w;
	mvprintw(x, y, "Time : %.2f", win.getElapsed());
	mvprintw(++x, y, "SCORE : %d", _score);
	++x;
	mvprintw(++x, y, "Player | Life");
	for (int i = 0; i < 16; i++)
		if (_player[i] && _player[i]->alive())
			mvprintw(++x, y, " %.2d    |  %d", _player[i]->getId(),
				_player[i]->getLife());
}

void EntityManager::addScore(int score)
{
	_score += score;
}
