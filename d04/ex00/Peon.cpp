/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:11:27 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 20:11:27 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include <iostream>

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}
Peon::Peon(Peon const &src) : Victim(src) {
	std::cout << "//COPY// Zog zog." << std::endl;
	*this = src;
}
Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}
Peon &Peon::operator=(Peon const &rhs) {
	if (this != &rhs) {
		this->setName(rhs.getName());
	}
	return *this;
}

void Peon::getPolymorphed() const{
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}

Peon::Peon(void) : Victim("HOW CAN YOU DO THAT"){
	//std::cout << "An instance of Peon has been created" << std::endl;
}
//std::ostream &Peon::operator<<(std::ostream &o, Peon const &i) {
//	o << "value of XXX : " << i.getXXX() << std::endl;
//	return o;
//}