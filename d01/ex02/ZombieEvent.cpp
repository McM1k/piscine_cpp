/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:56:29 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 13:56:29 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

void ZombieEvent::setZombieType(std::string type){
	ZombieEvent::_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	return new Zombie(name, ZombieEvent::_type);
}

Zombie* ZombieEvent::randomChump() {
	std::string names[10];
	names[0] = "Bobby";
	names[1] = "Sally";
	names[2] = "Jeremy";
	names[3] = "Franky";
	names[4] = "Johnny";
	names[5] = "Kenny";
	names[6] = "Stacy";
	names[7] = "Marty";
	names[8] = "Harry";
	names[9] = "Lenny";

	srand (time(NULL));
	Zombie *newZombie = new Zombie(names[rand() % 10], ZombieEvent::_type);
	newZombie->announce();
	return newZombie;
}

std::string ZombieEvent::_type = "normal";