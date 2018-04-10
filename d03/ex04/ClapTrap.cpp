/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:52:43 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/11 21:52:43 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>

std::string ClapTrap::intToString(int nb) {
	std::ostringstream o;
	o << nb;
	return o.str();
}

int ClapTrap::_unassignedNb = 0;

ClapTrap::ClapTrap(void) : _hitPoints(10),
						   _maxHitPoints(10),
						   _energyPoints(5),
						   _maxEnergyPoints(5),
						   _level(1),
						   _name("CL4P-TP" + intToString(ClapTrap::_unassignedNb)),
						   _meleeDamage(10),
						   _rangedDamage(5),
						   _armorReduction(0){
	std::cout << "An instance of generic ClapTrap has been created" << std::endl;
	std::string lifeSentences[6];
	lifeSentences[0] = "Hahaha... I ascend!";
	lifeSentences[1] = "Ha ha ha! I LIVE! Hahaha!";
	lifeSentences[2] = "Hahahahaha! I'm alive!";
	lifeSentences[3] = "Aw yeah!";
	lifeSentences[4] = "Wub wub wub wub... I'M ALIVE!";
	lifeSentences[5] = "I feel... complete! ... That's weird.";

	srand (time(NULL));
	std::cout << this->_name << " : " << lifeSentences[rand() % 6] << std::endl;
	ClapTrap::_unassignedNb++;
}
ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "An instance of ClapTrap has been created by copy" << std::endl;
	std::string lifeSentences[6];
	lifeSentences[0] = "Hahaha... I ascend!";
	lifeSentences[1] = "Ha ha ha! I LIVE! Hahaha!";
	lifeSentences[2] = "Hahahahaha! I'm alive!";
	lifeSentences[3] = "Aw yeah!";
	lifeSentences[4] = "Wub wub wub wub... I'M ALIVE!";
	lifeSentences[5] = "I feel... complete! ... That's weird.";

	srand (time(NULL));
	*this = src;
	std::cout << this->_name << " : " << lifeSentences[rand() % 6] << std::endl;
}
ClapTrap::~ClapTrap(void) {
	std::string deathSentences[13];
	deathSentences[0] = "I'll die the way I lived: annoying!";
	deathSentences[1] = "This could've gone better!";
	deathSentences[2] = "Oh yeah? Well, uh... yeah.";
	deathSentences[3] = "I'm leaking!";
	deathSentences[4] = "Good thing I don't have a soul!";
	deathSentences[5] = "Aww! Come on!";
	deathSentences[6] = "You can't kill me!";
	deathSentences[7] = "I'm too pretty to die!";
	deathSentences[8] = "Robot down!";
	deathSentences[9] = "Crap!";
	deathSentences[10] = "No, nononono NO!";
	deathSentences[11] = "I'll never go back to the bad place!";
	deathSentences[12] = "I have many regrets!";

	std::cout << this->_name << " : " << deathSentences[rand() % 13] << std::endl;
	std::cout << "An instance of ClapTrap has been destroyed" << std::endl;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs) {
		this->_hitPoints = rhs.getHitPoints();
		this->_maxHitPoints = rhs.getMaxHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
		this->_level = rhs.getLevel();
		this->_name = rhs.getName();
		this->_meleeDamage = rhs.getMeleeDamage();
		this->_rangedDamage = rhs.getRangedDamage();
		this->_armorReduction = rhs.getArmorReduction();
	}
	return *this;
}
ClapTrap::ClapTrap(std::string name) : _hitPoints(10),
						   _maxHitPoints(10),
						   _energyPoints(5),
						   _maxEnergyPoints(5),
						   _level(1),
						   _name("CL-" + name),
						   _meleeDamage(10),
						   _rangedDamage(5),
						   _armorReduction(0){
	std::cout << "An instance of ClapTrap has been created" << std::endl;
	std::string lifeSentences[6];
	lifeSentences[0] = "Hahaha... I ascend!";
	lifeSentences[1] = "Ha ha ha! I LIVE! Hahaha!";
	lifeSentences[2] = "Hahahahaha! I'm alive!";
	lifeSentences[3] = "Aw yeah!";
	lifeSentences[4] = "Wub wub wub wub... I'M ALIVE!";
	lifeSentences[5] = "I feel... complete! ... That's weird.";

	srand (time(NULL));
	std::cout << this->_name << " : " << lifeSentences[rand() % 6] << std::endl;
}
ClapTrap::ClapTrap(unsigned int hit, unsigned int maxHit, unsigned int energy,
				   unsigned int maxEnergy, unsigned int level, std::string name,
				   unsigned int melee, unsigned int range,
				   unsigned int armor) :
	_hitPoints(hit), _maxHitPoints(maxHit), _energyPoints(energy),
	_maxEnergyPoints(maxEnergy), _level(level), _name(name),
	_meleeDamage(melee), _rangedDamage(range), _armorReduction(armor) {
	std::cout << "An instance of ClapTrap has been created" << std::endl;
	std::string lifeSentences[6];
	lifeSentences[0] = "Hahaha... I ascend!";
	lifeSentences[1] = "Ha ha ha! I LIVE! Hahaha!";
	lifeSentences[2] = "Hahahahaha! I'm alive!";
	lifeSentences[3] = "Aw yeah!";
	lifeSentences[4] = "Wub wub wub wub... I'M ALIVE!";
	lifeSentences[5] = "I feel... complete! ... That's weird.";

	srand (time(NULL));
	std::cout << this->_name << " : " << lifeSentences[rand() % 6] << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "CL4P-TP " << this->_name << " takes an attack at " << amount;
	std::cout << " reduced by " << this->_armorReduction << ", causing ";
	if (amount < this->_armorReduction)
		amount = 0;
	else
		amount -= this->_armorReduction;

	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << amount << " points of damage. ";
	std::cout << this->_hitPoints << "HP left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "CL4P-TP " << this->_name;
	std::cout << " is repaired for " << amount << "HP. ";
	if (amount > this->_maxHitPoints - this->_hitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << this->_hitPoints << "HP left" << std::endl;
}

unsigned int ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}
unsigned int ClapTrap::getMaxHitPoints() const {
	return this->_maxHitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}
unsigned int ClapTrap::getMaxEnergyPoints() const {
	return this->_maxEnergyPoints;
}
unsigned int ClapTrap::getLevel() const {
	return this->_level;
}
std::string ClapTrap::getName() const {
	return this->_name;
}
unsigned int ClapTrap::getMeleeDamage() const {
	return this->_meleeDamage;
}
unsigned int ClapTrap::getRangedDamage() const {
	return this->_rangedDamage;
}
unsigned int ClapTrap::getArmorReduction() const {
	return this->_armorReduction;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &i) {
	o << "hitPoints : " << i.getHitPoints() << std::endl;
	o << "maxHitPoints : " << i.getMaxHitPoints() << std::endl;
	o << "energyPoints : " << i.getEnergyPoints() << std::endl;
	o << "maxEnergyPoints : " << i.getMaxEnergyPoints() << std::endl;
	o << "level : " << i.getLevel() << std::endl;
	o << "name : " << i.getName() << std::endl;
	o << "meleeDamage : " << i.getMeleeDamage() << std::endl;
	o << "rangeDamage : " << i.getRangedDamage() << std::endl;
	o << "armorReduction : " << i.getArmorReduction() << std::endl;
	return o;
}