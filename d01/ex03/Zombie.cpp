/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:56:10 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 13:56:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, std::string type) : name(name), type(type){
	std::cout << this->name << " of type " << this->type << " has been created" <<std::endl;
}

Zombie::Zombie(){
	std::cout << "New zombie has been created" <<std::endl;
}

void Zombie::announce() const {
	std::cout << "<" << this->name << " (" << this->type << ")> ";
	if (!this->type.compare("pirate"))
		std::cout << "Yaaaaarrrrrrrrrrr..." << std::endl;
	else if (!this->type.compare("knight"))
		std::cout << "Ye olde Brainssss..." << std::endl;
	else
		std::cout << "Braiiiiiiinnnssss..." << std::endl;
}


Zombie::~Zombie(){
	std::cout << this->name << " of type " << this->type << " has been destroyed" <<std::endl;
}