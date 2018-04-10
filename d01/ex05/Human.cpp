/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:54:33 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 18:54:33 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() : brain(Brain()){

}

Human::~Human() {

}

std::string Human::identify() const{
	return this->brain.identify();
}

const Brain &Human::getBrain() const{
	const Brain &brainRef = this->brain;
	return brainRef;
}