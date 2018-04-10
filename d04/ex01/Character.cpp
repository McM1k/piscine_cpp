/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:17:54 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 20:17:54 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

/*
 * Coplien
 */
Character::Character(void) {
	//std::cout << "An instance of Character has been created" << std::endl;
}

Character::Character(Character const &src) {
	//std::cout << "An instance of Character has been created by copy" << std::endl;
	*this = src;
}

Character::~Character(void) {
	//std::cout << "An instance of Character has been destroyed" << std::endl;
}

Character &Character::operator=(Character const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_AP = rhs.getAP();
		this->_weapon = rhs.getWeapon();
	}
	return *this;
}

/*
 * Constructors
 */
Character::Character(const std::string &name) : _name(name), _AP(40), _weapon(NULL){
}

/*
 * Getters
 */
std::string Character::getName() const {
	return this->_name;
}

int Character::getAP() const {
	return this->_AP;
}

AWeapon* Character::getWeapon() const {
	return this->_weapon;
}

/*
 * Setters
 */

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, Character const &i) {
	o << i.getName() << " has " << i.getAP() << " AP";
	if (i.getWeapon())
		o << " and wields a " <<i.getWeapon()->getName() << std::endl;
	else
		o << " and is unarmed" << std::endl;
	return o;
}

/*
 * Other
 */
void Character::recoverAP() {
	if (this->_AP > 39)
		return;
	else if (this->_AP > 30)
		this->_AP = 40;
	else
		this->_AP += 10;
}

void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if ((!this->_weapon) || this->_AP < this->_weapon->getAPCost())
		return;
	std::cout << this->_name << " attacks " << enemy->getType();
	std::cout << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	enemy->takeDamage(this->_weapon->getDamage());
	this->_AP -= this->_weapon->getAPCost();
	if (enemy->getHP() <= 0)
		delete enemy;
}