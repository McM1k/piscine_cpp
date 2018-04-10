#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include <string>
# include "IEntity.hpp"

class Projectile : public IEntity
{
public:
	Projectile();
	Projectile(float px, float py, float dx, float dy, bool enemy);
	Projectile(Projectile const &copy);
	virtual ~Projectile();
	Projectile &operator=(Projectile const &rhs);
	void set(float px, float py, float dx, float dy, bool enemy);
	int getX() const;
	int getY() const;
	bool isEnemy() const;
	virtual void update(Window &win);
	virtual void render(Window &win);
	bool alive();
	void destroy();
protected:
private:
	float _px;
	float _py;
	float _dx;
	float _dy;
	bool _alive;
	bool _enemy;
};

#endif
