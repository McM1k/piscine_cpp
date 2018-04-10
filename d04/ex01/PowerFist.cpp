/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:03:17 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 15:03:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {
	//std::cout << "An instance of PowerFist has been created" << std::endl;
}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src) {
	//std::cout << "An instance of PowerFist has been created by copy" << std::endl;
	*this = src;
}

PowerFist::~PowerFist(void) {
	//std::cout << "An instance of PowerFist has been destroyed" << std::endl;
}

PowerFist &PowerFist::operator=(PowerFist const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_damage = rhs.getDamage();
		this->_APCost = rhs.getAPCost();
	}
	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

//std::ostream &operator<<(std::ostream &o, PowerFist const &i) {
//	o << "value of XXX : " << i.getXXX() << std::endl;
//	return o;
//}