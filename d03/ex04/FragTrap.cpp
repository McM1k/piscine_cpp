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

FragTrap::FragTrap(void) : ClapTrap(100,100,100,100,1,"FR4G-TP" + ClapTrap::intToString(FragTrap::_unassignedNb),30,20,5) {
	std::cout << "An instance of generic FragTrap has been created" << std::endl;
	FragTrap::_unassignedNb++;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src){
	std::cout << "An instance of FragTrap has been created by copy" << std::endl;
	*this = src;
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

FragTrap::~FragTrap(void) {
	std::cout << "An instance of FragTrap has been destroyed" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(100,100,100,100,1,"FR-" + name,30,20,5) {
	std::cout << "An instance of FragTrap has been created" << std::endl;
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

int FragTrap::_unassignedNb = 0;
