/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:55:53 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 19:55:53 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include <iostream>

/*
 * Coplien
 */
SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) {
	//std::cout << "An instance of SuperMutant has been created by copy" << std::endl;
	*this = src;
}

SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs) {
	if (this != &rhs) {
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}

/*
 * Constructors
 */

/*
 * Getters
 */

/*
 * Setters
 */

/*
 * ToString
 */
//std::ostream &operator<<(std::ostream &o, SuperMutant const &i) {
//	o << "value of XXX : " << i.getXXX() << std::endl;
//	return o;
//}

/*
 * Other
 */

void SuperMutant::takeDamage(int value) {
	Enemy::takeDamage(value - 3);
}