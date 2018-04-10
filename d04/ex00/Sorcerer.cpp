/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:11:24 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 20:11:24 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}
Sorcerer::Sorcerer(Sorcerer const &src) {
	*this = src;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}
Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", " << this->_title;
	std::cout << ", is dead. Consequences will never be the same !" << std::endl;
}
Sorcerer &Sorcerer::operator=(Sorcerer const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
	}
	return *this;
}

void Sorcerer::polymorph(const Victim &victim) const {
	victim.getPolymorphed();
}

std::string Sorcerer::getName() const {
	return this->_name;
}
std::string Sorcerer::getTitle() const {
	return this->_title;
}
std::ostream &operator<<(std::ostream &o, Sorcerer const &i) {
	o << "I am " << i.getName() << ", " << i.getTitle();
	o << ", and I like ponies !" << std::endl;
	return o;
}
Sorcerer::Sorcerer(void) {
	std::cout << "HOW CAN YOU DO THAT???" << std::endl;
}
