/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:45:51 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 13:45:51 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(void) : ClapTrap(60,60,120,120,1,"NINJ4-TP" + ClapTrap::intToString(NinjaTrap::_unassignedNb),5,60,0) {
	std::cout << "An instance of generic NinjaTrap has been created" << std::endl;
	NinjaTrap::_unassignedNb++;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src){
	std::cout << "An instance of NinjaTrap has been created by copy" << std::endl;
	*this = src;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
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

NinjaTrap::~NinjaTrap(void) {
	std::cout << "An instance of NinjaTrap has been destroyed" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(60,60,120,120,1,"NI-" + name,5,60,0) {
	std::cout << "An instance of NinjaTrap has been created" << std::endl;
}

void NinjaTrap::rangedAttack(const std::string &target) const {
	std::cout << "NINJ4-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDamage << " points of damage !";
	std::cout << std::endl;
}

void NinjaTrap::meleeAttack(const std::string &target) const {
	std::cout << "NINJ4-TP " << this->_name << " melee attacks " << target;
	std::cout << ", causing " << this->_meleeDamage << " points of damage !";
	std::cout << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &fr) {
	std::cout << "NINJ4-TP " << this->_name << " use NinjaShoebox on " << fr.getName() << ". ";
	std::cout << "In short, he uses his fast movements to evade bullets comming at him, and stabs his ennemy" << std::endl;
	fr.takeDamage(80);
}
void NinjaTrap::ninjaShoebox(ScavTrap &sc) {
	std::cout << "NINJ4-TP " << this->_name << " use NinjaShoebox on " << sc.getName() << ". ";
	std::cout << "In short, he gets distracted by the stupidity of his ennemy and manage to hurt himself" << std::endl;
	this->takeDamage(10);
}
void NinjaTrap::ninjaShoebox(ClapTrap &cl) {
	std::cout << "NINJ4-TP " << this->_name << " use NinjaShoebox on " << cl.getName() << ". ";
	std::cout << "Concerned about the purpose for which this clap-trap was concieved, he break his ennemy neck to end his sad and lonely simulated life of door manner" << std::endl;
	cl.takeDamage(999);
}
void NinjaTrap::ninjaShoebox(NinjaTrap &ni) {
	std::cout << "NINJ4-TP " << this->_name << " use NinjaShoebox on " << ni.getName() << ". ";
	std::cout << "In short, they politely exchange data about their ninja techniques. Both regain 5HP." << std::endl;
	this->beRepaired(5);
	ni.beRepaired(5);
}

int NinjaTrap::_unassignedNb = 0;
