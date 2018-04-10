/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:27:34 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 16:27:34 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(void) : ClapTrap(100,100,120,120,1,"SUP3R-TP" + ClapTrap::intToString(SuperTrap::_unassignedNb),30,60,5) {
	std::cout << "An instance of generic SuperTrap has been created" << std::endl;
	SuperTrap::_unassignedNb++;
}

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(src){
	std::cout << "An instance of SuperTrap has been created by copy" << std::endl;
	*this = src;
}

SuperTrap::~SuperTrap(void) {
	std::cout << "An instance of SuperTrap has been destroyed" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs){
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

SuperTrap::SuperTrap(std::string name) : ClapTrap(100,100,120,120,1,"SU-" + name,30,60,5){
	std::cout << "An instance of SuperTrap has been created" << std::endl;
}

void SuperTrap::rangedAttack(const std::string &target) const {
	std::cout << "SUP3R-";
	this->FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(const std::string &target) const {
	std::cout << "SUP3R-";
	this->NinjaTrap::meleeAttack(target);
}

int SuperTrap::_unassignedNb = 0;