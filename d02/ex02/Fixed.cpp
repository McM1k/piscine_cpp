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
#include <cmath>

Fixed::Fixed(void) : _rawBits(0) {
	//std::cout << "default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const &src) {
	//std::cout << "copy constructor called" << std::endl;
	*this = src;
}
Fixed::Fixed(int const intValue) : _rawBits(intValue << Fixed::_fractionalBits){
}
Fixed::Fixed(float const floatValue) :
		_rawBits(roundf(floatValue * (1 << Fixed::_fractionalBits))){
}
Fixed::~Fixed(void) {
	//std::cout << "destructor called" << std::endl;
}
Fixed &Fixed::operator=(Fixed const &rhs) {
	//std::cout << "assignation operator called" << std::endl;
	if (this != &rhs) {
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}
// COMPARISONS
bool Fixed::operator>(Fixed const &rhs) const {
	return (this->_rawBits > rhs.getRawBits());
}
bool Fixed::operator<(Fixed const &rhs) const {
	return (this->_rawBits < rhs.getRawBits());
}
bool Fixed::operator>=(Fixed const &rhs) const {
	return (this->_rawBits >= rhs.getRawBits());
}
bool Fixed::operator<=(Fixed const &rhs) const {
	return (this->_rawBits <= rhs.getRawBits());
}
bool Fixed::operator==(Fixed const &rhs) const {
	return (this->_rawBits == rhs.getRawBits());
}
bool Fixed::operator!=(Fixed const &rhs) const {
	return (this->_rawBits != rhs.getRawBits());
}
// QUICKMATHS (2 + 2 = 4 - 1 it's 3)
Fixed Fixed::operator+(Fixed const &rhs) const {
	Fixed fixed(*this);
	fixed._rawBits += rhs.getRawBits();
	return fixed;
}
Fixed Fixed::operator-(Fixed const &rhs) const {
	Fixed fixed(*this);
	fixed._rawBits -= rhs.getRawBits();
	return fixed;
}
Fixed Fixed::operator*(Fixed const &rhs) const {
	Fixed fixed(*this);
	fixed._rawBits *= rhs.getRawBits();
	fixed._rawBits /= (1 << Fixed::_fractionalBits);
	return fixed;
}
Fixed Fixed::operator/(Fixed const &rhs) const {
	Fixed fixed(*this);
	fixed._rawBits *= (1 << Fixed::_fractionalBits);
	fixed._rawBits /= rhs.getRawBits();
	return fixed;
}
// INCREMENTATIONS
Fixed &Fixed::operator++() {
	this->_rawBits++;
	return *this;
}
Fixed Fixed::operator++(int dummy) {
	Fixed fixed(*this);
	dummy++;
	this->_rawBits++;
	return fixed;
}
Fixed &Fixed::operator--() {
	this->_rawBits--;
	return *this;
}
Fixed Fixed::operator--(int dummy) {
	Fixed fixed(*this);
	dummy--;
	this->_rawBits--;
	return fixed;
}
// MIN & MAX
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}
// GETTER, SETTER AND TO()
int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}
void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}
int Fixed::toInt() const {
	return (_rawBits >> Fixed::_fractionalBits);
}
float Fixed::toFloat() const {
	return (float)(_rawBits / (float)(1 << Fixed::_fractionalBits));
}

const int Fixed::_fractionalBits = 8;

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}