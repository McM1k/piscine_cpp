/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:33:07 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/10 14:33:07 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "assignation operator called" << std::endl;
	if (this != &rhs) {
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

const int Fixed::_fractionalBits = 8;

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << "value of _rawBits : " << i.getRawBits();
	o << ", value of _fractionalBits : " << Fixed::_fractionalBits << std::endl;
	return o;
}