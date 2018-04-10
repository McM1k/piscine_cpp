/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:06:09 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/11 21:06:09 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>

std::string ScavTrap::intToString(int nb) {
	std::ostringstream o;
	o << nb;
	return o.str();
}

ScavTrap::ScavTrap(void) :
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(50),
		_maxEnergyPoints(50),
		_level(1),
		_name("SC4V-TP" + intToString(ScavTrap::_unassignedNb)),
		_meleeDamage(20),
		_rangedDamage(15),
		_armorReduction(3) {
	std::string lifeSentences[6];
	lifeSentences[0] = "Hahaha... I ascend!";
	lifeSentences[1] = "Ha ha ha! I LIVE! Hahaha!";
	lifeSentences[2] = "Hahahahaha! I'm alive!";
	lifeSentences[3] = "Aw yeah!";
	lifeSentences[4] = "Wub wub wub wub... I'M ALIVE!";
	lifeSentences[5] = "I feel... complete! ... That's weird.";

	srand (time(NULL));
	std::cout << this->_name << " : " << lifeSentences[rand() % 6] << std::endl;
	ScavTrap::_unassignedNb++;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	//std::cout << "An instance of ScavTrap has been created by copy" << std::endl;
	*this = src;
	srand (time(NULL));
}

ScavTrap::~ScavTrap(void) {
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
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
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

ScavTrap::ScavTrap(std::string name) :
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(50),
		_maxEnergyPoints(50),
		_level(1),
		_name(name),
		_meleeDamage(20),
		_rangedDamage(15),
		_armorReduction(3) {
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

void ScavTrap::rangedAttack(const std::string &target) const {
	std::cout << "SC4V-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDamage << " points of damage !";
	std::cout << std::endl;
}

void ScavTrap::meleeAttack(const std::string &target) const {
	std::cout << "SC4V-TP " << this->_name << " melee attacks " << target;
	std::cout << ", causing " << this->_meleeDamage << " points of damage !";
	std::cout << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "SC4V-TP " << this->_name << " takes an attack at " << amount;
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

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "SC4V-TP " << this->_name;
	std::cout << " is repaired for " << amount << "HP. ";
	if (amount > this->_maxHitPoints - this->_hitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << this->_hitPoints << "HP left" << std::endl;
}

void ScavTrap::challengeNewcomer() {
	std::string challenges[6];
	challenges[0] = "SHOOT ME IN THE HEAD!!!!! AND I'LL LET YOU PASS!!!";
	challenges[1] = "Hello stranger! If you could gently rub my back, i'll let you pass.";
	challenges[2] = "Oh, another being! Let's Party! Then I'll open the door to our lair.";
	challenges[3] = "If you help me solve this paradox, I'll let you pass";
	challenges[4] = "YOU SHALL NOT PASS!!! Unless you show me your magic tricks of course.";
	challenges[5] = "Hey hey! If you want to pass, you're gonna have to give me a high five. Come on, I'm waiting...";

	std::cout << this->_name << " : " << challenges[rand() % 6] << std::endl;
}

unsigned int ScavTrap::getHitPoints() const {
	return this->_hitPoints;
}
unsigned int ScavTrap::getMaxHitPoints() const {
	return this->_maxHitPoints;
}
unsigned int ScavTrap::getEnergyPoints() const {
	return this->_energyPoints;
}
unsigned int ScavTrap::getMaxEnergyPoints() const {
	return this->_maxEnergyPoints;
}
unsigned int ScavTrap::getLevel() const {
	return this->_level;
}
std::string ScavTrap::getName() const {
	return this->_name;
}
unsigned int ScavTrap::getMeleeDamage() const {
	return this->_meleeDamage;
}
unsigned int ScavTrap::getRangedDamage() const {
	return this->_rangedDamage;
}
unsigned int ScavTrap::getArmorReduction() const {
	return this->_armorReduction;
}

int ScavTrap::_unassignedNb = 0;

std::ostream &operator<<(std::ostream &o, ScavTrap const &i) {
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