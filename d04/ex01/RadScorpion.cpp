/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:07:08 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 20:07:08 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"
#include <iostream>

/*
 * Coplien
 */
RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion"){
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src) {
	//std::cout << "An instance of RadScorpion has been created by copy" << std::endl;
	*this = src;
}

RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &rhs) {
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
//std::ostream &operator<<(std::ostream &o, RadScorpion const &i) {
//	o << "value of XXX : " << i.getXXX() << std::endl;
//	return o;
//}

/*
 * Other
 */