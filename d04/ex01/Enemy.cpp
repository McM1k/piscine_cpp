/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:13:28 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 17:13:28 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <iostream>

/*
 * COPLIEN
 */
Enemy::Enemy(void) {
	//std::cout << "An instance of Enemy has been created" << std::endl;
}

Enemy::Enemy(Enemy const &src) {
	//std::cout << "An instance of Enemy has been created by copy" << std::endl;
	*this = src;
}

Enemy::~Enemy(void) {
	//std::cout << "An instance of Enemy has been destroyed" << std::endl;
}

Enemy &Enemy::operator=(Enemy const &rhs) {
	if (this != &rhs) {
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}

/*
 * Constructors
 */
Enemy::Enemy(int hp, const std::string &type)
		: _hp(hp), _type(type) {
	//std::cout << "A new " << type << " is born !" << std::endl;
}

/*
 * Getters
 */
int Enemy::getHP() const {
	return this->_hp;
}

std::string Enemy::getType() const {
	return this->_type;
}

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, Enemy const &i) {
	o << "value of hp : " << i.getHP() << std::endl;
	o << "value of type : " << i.getType() << std::endl;
	return o;
}

/*
 * Other
 */
void Enemy::takeDamage(int value) {
	if (value < 1)
		return;
	else if (value > this->_hp)
		value = this->_hp;
	this->_hp -= value;
}