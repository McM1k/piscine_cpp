/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:19:17 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/11 19:19:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(void) {
	FragTrap *ft0 = new FragTrap();
	FragTrap *ft1 = new FragTrap("P0UL3T");
	FragTrap *ft2 = new FragTrap(*ft1);

	std::cout << std::endl << *ft0;
	std::cout << std::endl << *ft1;
	std::cout << std::endl << *ft2 << std::endl;

	ft0->meleeAttack("DUMMY-TP");
	ft1->rangedAttack("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	std::cout <<std::endl;
	ft0->takeDamage(3);
	ft1->takeDamage(15);
	ft2->takeDamage(110);
	std::cout <<std::endl;
	ft0->beRepaired(3);
	ft1->beRepaired(20);
	ft2->beRepaired(15);
	std::cout <<std::endl;
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	std::cout <<std::endl;
	delete ft2;
	delete ft1;
	delete ft0;
	return 0;
}