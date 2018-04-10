/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:11:22 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 20:11:22 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Victim *jack = new Peon("Jack");
	std::cout << robert << jim << joe << *jack;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(*jack);
	delete jack;
	return 0;
}