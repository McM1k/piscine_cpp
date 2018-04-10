/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:37:47 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 16:37:47 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

ZombieHorde::ZombieHorde(int n, std::string type) : n(n){
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

	srand(time(NULL));
	this->horde = new Zombie[n];

	int i = 0;
	while (i < n) {
		this->horde[i].name = names[rand() % 10];
		this->horde[i].type = type;
		i++;
	}
	std::cout << "A horde of " << n << " zombies of type " << type << " are now brainstorming." << std::endl;
}

ZombieHorde::~ZombieHorde() {
	std::cout << "A horde of " << this->n << " zombies of type " << this->horde[0].type << " has been destroyed." << std::endl;
	delete [] this->horde;
}

void ZombieHorde::announce() const {
	int i = 0;
	while (i < this->n){
		this->horde[i].announce();
		i++;
	}
}