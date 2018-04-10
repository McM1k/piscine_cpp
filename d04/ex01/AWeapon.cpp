/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:10:59 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 14:10:59 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include <iostream>

AWeapon::AWeapon(void) {
	//std::cout << "An instance of AWeapon has been created" << std::endl;
}

AWeapon::AWeapon(AWeapon const &src) {
	//std::cout << "An instance of AWeapon has been created by copy" << std::endl;
	*this = src;
}

AWeapon::~AWeapon(void) {
	//std::cout << "An instance of AWeapon has been destroyed" << std::endl;
}

AWeapon &AWeapon::operator=(AWeapon const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_damage = rhs.getDamage();
		this->_APCost = rhs.getAPCost();
	}
	return *this;
}

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
		: _name(name), _damage(damage), _APCost(apcost) {
	//std::cout << "A new " << name << " has been created !" << std::endl;
}

//
//std::ostream &operator<<(std::ostream &o, AWeapon const &i) {
//	o << "value of XXX : " << i.getXXX() << std::endl;
//	return o;
//}

const std::string AWeapon::getName() const {
	return this->_name;
}

int AWeapon::getAPCost() const {
	return this->_APCost;
}

int AWeapon::getDamage() const {
	return this->_damage;
}