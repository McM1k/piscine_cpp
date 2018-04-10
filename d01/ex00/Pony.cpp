/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:07:16 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 10:07:16 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"


Pony::Pony(std::string location) : location(location) {
	if (!(this->location).compare("OnTheHeap")) {
		this->favoriteMeal = "cupcake";
		this->poop = "rainbow";

		std::cout << "A happy Pony" << this->location << " has been created." << std::endl;
	}
	else if (!(this->location).compare("OnTheStack")) {
		this->favoriteMeal = "magic sugar";
		this->poop = "star dust";

		std::cout << "A happy Pony" << this->location << " has been created." << std::endl;
	}
	else {
		this->favoriteMeal = "raw wood";
		this->poop = "small bits of coal";

		std::cout << "A sad and lonely Pony has been created." << std::endl;
	}
}

Pony::~Pony() {
	if (!(this->location).compare("OnTheHeap"))
		std::cout << "Pony" << this->location << " has been destroyed." << std::endl;
	else if (!(Pony::location).compare("OnTheStack"))
		std::cout << "Pony" << this->location << " has been destroyed." << std::endl;
	else
		std::cout << "The life of endless suffering of the lonely Pony has come to an end." << std::endl;
}

void Pony::doSomeStuff() const {
	if (!(this->favoriteMeal).compare("raw wood"))
		std::cout << "The lonely pony eats ";
	else
		std::cout << "The pony" << this->location << " eats ";

	std::cout << this->favoriteMeal << "." << std::endl;
	std::cout << "Then, he poops " << this->poop << "." << std::endl;
	std::cout << "A true pony" << this->location << "'s life indeed!" << std::endl;
}