/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:57:09 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/11 11:57:09 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::string intToString(int nb) {
	std::ostringstream o;
	o << nb;
	return o.str();
}

FragTrap::FragTrap(void) :
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(100),
		_maxEnergyPoints(100),
		_level(1),
		_name("FR4G-TP" + intToString(FragTrap::_unassignedNb)),
		_meleeDamage(30),
		_rangedDamage(20),
		_armorReduction(5) {
	std::string lifeSentences[6];
	lifeSentences[0] = "Hahaha... I ascend!";
	lifeSentences[1] = "Ha ha ha! I LIVE! Hahaha!";
	lifeSentences[2] = "Hahahahaha! I'm alive!";
	lifeSentences[3] = "Aw yeah!";
	lifeSentences[4] = "Wub wub wub wub... I'M ALIVE!";
	lifeSentences[5] = "I feel... complete! ... That's weird.";

	srand (time(NULL));
	std::cout << this->_name << " : " << lifeSentences[rand() % 6] << std::endl;
	FragTrap::_unassignedNb++;
}

FragTrap::FragTrap(FragTrap const &src) {
	//std::cout << "An instance of FragTrap has been created by copy" << std::endl;
	*this = src;
	srand (time(NULL));
}

FragTrap::~FragTrap(void) {
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

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
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

FragTrap::FragTrap(std::string name) :
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(100),
		_maxEnergyPoints(100),
		_level(1),
		_name(name),
		_meleeDamage(30),
		_rangedDamage(20),
		_armorReduction(5) {
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

void FragTrap::rangedAttack(const std::string &target) const {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDamage << " points of damage !";
	std::cout << std::endl;
}

void FragTrap::meleeAttack(const std::string &target) const {
	std::cout << "FR4G-TP " << this->_name << " melee attacks " << target;
	std::cout << ", causing " << this->_meleeDamage << " points of damage !";
	std::cout << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	std::cout << "FR4G-TP " << this->_name << " takes an attack at " << amount;
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

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " is repaired for " << amount << "HP. ";
	if (amount > this->_maxHitPoints - this->_hitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << this->_hitPoints << "HP left" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(const std::string &target) {
	if (this->_energyPoints < 25) {
		std::cout << this->_name << " : " << "ERRRRRR - NOT ENOUGH ENERGY POINTS - PLEASE COLLECT SOME FRESH WUB-WUB JUICE" << std::endl;
		return ;
	}
	std::string attacks[5];
	attacks[0] = " starts emitting bipping sounds, and then explodes ";
	attacks[1] = " pulls out an axe and starts rampaging ";
	attacks[2] = " thinks about how he is lonely, making his target depressed ";
	attacks[3] = " pulls out an electric guitar and starts playing the heaviest riff of his life ";
	attacks[4] = " recompile his code to become one with his weapon ";

	this->_energyPoints -= 25;
	std::cout << "FR4G-TP " << this->_name << attacks[rand() % 5];
	std::cout << "for 25 energyPoints, causing " << this->_meleeDamage;
	std::cout << " points of damage to " << target << std::endl;
}

unsigned int FragTrap::getHitPoints() const {
	return this->_hitPoints;
}
unsigned int FragTrap::getMaxHitPoints() const {
	return this->_maxHitPoints;
}
unsigned int FragTrap::getEnergyPoints() const {
	return this->_energyPoints;
}
unsigned int FragTrap::getMaxEnergyPoints() const {
	return this->_maxEnergyPoints;
}
unsigned int FragTrap::getLevel() const {
	return this->_level;
}
std::string FragTrap::getName() const {
	return this->_name;
}
unsigned int FragTrap::getMeleeDamage() const {
	return this->_meleeDamage;
}
unsigned int FragTrap::getRangedDamage() const {
	return this->_rangedDamage;
}
unsigned int FragTrap::getArmorReduction() const {
	return this->_armorReduction;
}

int FragTrap::_unassignedNb = 0;

std::ostream &operator<<(std::ostream &o, FragTrap const &i) {
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