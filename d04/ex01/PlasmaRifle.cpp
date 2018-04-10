/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:03:15 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 15:03:15 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {
	//std::cout << "An instance of PlasmaRifle has been created" << std::endl;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src) {
	//std::cout << "An instance of PlasmaRifle has been created by copy" << std::endl;
	*this = src;
}

PlasmaRifle::~PlasmaRifle(void) {
	//std::cout << "An instance of PlasmaRifle has been destroyed" << std::endl;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_damage = rhs.getDamage();
		this->_APCost = rhs.getAPCost();
	}
	return *this;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

//std::ostream &operator<<(std::ostream &o, PlasmaRifle const &i) {
//	o << "value of XXX : " << i.getXXX() << std::endl;
//	return o;
//}