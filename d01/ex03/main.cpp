/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:40:23 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 16:40:23 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

void fct(ZombieHorde *zombieHorde) {
	std::cout << "--entering function---" << std::endl;
	zombieHorde->announce();
	std::cout << "and they will not be destroyed if i leave the function" << std::endl;
	std::cout << "--leaving function---" << std::endl;
}

int main() {
	std::cout << "i can create a horde of zombies" << std::endl;

	int number_of_zombies = 7;
	ZombieHorde *zombieHorde = new ZombieHorde(number_of_zombies, "pirate");
	std::cout << "i can make them talk, but since they are pirate zombies, their groans are a bit weird" << std::endl;
	zombieHorde->announce();
	std::cout << "i can pass them to another function since the horde is allocated with new" << std::endl;
	fct(zombieHorde);
	zombieHorde->announce();
	std::cout << "aaaaand that's it, sorry for the lack of RP, i'm gonna kill them now, i'm bored." << std::endl;
	zombieHorde->announce();
	std::cout << "BOOOOOOM" << std::endl;
	delete zombieHorde;

	return (0);
}