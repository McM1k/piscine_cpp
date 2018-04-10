#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	Enemy* a = new SuperMutant();
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << *zaz;
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->attack(a);
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << a->getHP();
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << a->getHP();
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << a->getHP();
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << a->getHP();
	std::cout << *zaz;
	zaz->attack(a);
	std::cout << a->getHP();
	std::cout << *zaz;
	return 0;
}