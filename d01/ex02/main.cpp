/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:56:40 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 13:56:40 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

void fct(Zombie *heapZombie, Zombie *randZombie){
	std::cout << std::endl << "We just entered the scope of a new fonction , and the two knight Zombies followed us in!" << std::endl;
	randZombie->announce();
	heapZombie->announce();
	Zombie stackZombie = Zombie("Gol D. Roger", "pirate");
	stackZombie.announce();
	randZombie->announce();
	heapZombie->announce();
	std::cout << "We will leave the function so it will kill the pirate zombie, but before that ..." << std::endl;
	randZombie->announce();
	heapZombie->announce();
	delete randZombie;
	heapZombie->announce();
	std::cout << "now we exit the function" << std::endl << std::endl;
}

int main() {
	std::cout << std::endl << "knights zombies are allocated while pirates zombies arent" << std::endl << std::endl;
	ZombieEvent::setZombieType("knight");
	Zombie *heapZombie = ZombieEvent::newZombie("Richard Coeur de Lion");
	heapZombie->announce();
	Zombie *randZombie = ZombieEvent::randomChump();
	randZombie->announce();
	heapZombie->announce();

	fct(heapZombie, randZombie);

	std::cout << "And for the last zombie, since he's allocated, we need to kill him manually by using a pointer and delete like we did for the random zombie" << std::endl;
	delete heapZombie;
	std::cout << std::endl;
	return (0);
}