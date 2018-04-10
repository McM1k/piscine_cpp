/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:11:25 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 20:11:25 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>

Victim::Victim(std::string name) : _name(name){
	std::cout << "Some random victim called " << this->_name;
	std::cout << " just popped !" << std::endl;
}
Victim::Victim(Victim const &src) {
	*this = src;
	std::cout << "Some random victim called " << this->_name;
	std::cout << " just popped by copy !" << std::endl;
}
Victim::~Victim(void) {
	std::cout << "Victim " << this->_name;
	std::cout << " just died for no apparent reason !" << std::endl;
}
Victim &Victim::operator=(Victim const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
	}
	return *this;
}

void Victim::getPolymorphed() const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::string Victim::getName() const {
	return this->_name;
}
void Victim::setName(std::string name) {
	this->_name = name;
}
std::ostream &operator<<(std::ostream &o, Victim const &i) {
	o << "I'm " << i.getName();
	o << " and I like otters !" << std::endl;
	return o;
}
Victim::Victim(void) {
	std::cout << "HOW CAN YOU DO THAT???" << std::endl;
}
