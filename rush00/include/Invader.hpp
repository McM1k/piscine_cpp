#ifndef INVADER_HPP
# define INVADER_HPP

# include <string>
# include "IEnemy.hpp"

class Invader : public IEnemy
{
public:
	Invader();
	Invader(double time, int x, int y);
	Invader(Invader const &copy);
	virtual ~Invader();
	Invader &operator=(Invader const &rhs);
	virtual void update(Window &win);
	virtual void render(Window &win);
	virtual bool collide(int x, int y);
	virtual bool alive();
protected:
private:
	int _px;
	int _py;
	int _rx;
	int _ry;
	double _creatTime;
	bool _alive;
	int _lastMove;
};

#endif
