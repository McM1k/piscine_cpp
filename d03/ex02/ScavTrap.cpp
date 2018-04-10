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

ScavTrap::ScavTrap(void) : ClapTrap(100,100,50,50,1,"SC4V-TP" + ClapTrap::intToString(ScavTrap::_unassignedNb),20,15,3){
	std::cout << "An instance of generic ScavTrap has been created" << std::endl;
	ScavTrap::_unassignedNb++;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src){
	std::cout << "An instance of ScavTrap has been created by copy" << std::endl;
	*this = src;
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

ScavTrap::~ScavTrap(void) {
	std::cout << "An instance of ScavTrap has been destroyed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(100,100,50,50,1,"SC-" + name,20,15,3) {
	std::cout << "An instance of ScavTrap has been created" << std::endl;
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

int ScavTrap::_unassignedNb = 0;
