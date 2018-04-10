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
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
	FragTrap *ft0 = new FragTrap();
	FragTrap *ft1 = new FragTrap("P0UL3T");
	FragTrap *ft2 = new FragTrap(*ft1);
	ScavTrap *sc0 = new ScavTrap();
	ScavTrap *sc1 = new ScavTrap("P0UL3T");
	ScavTrap *sc2 = new ScavTrap(*sc1);
	ClapTrap *cl0 = new ClapTrap();
	ClapTrap *cl1 = new ClapTrap("P0UL3T");
	ClapTrap *cl2 = new ClapTrap(*cl1);

	std::cout << std::endl << *ft0;
	std::cout << std::endl << *ft1;
	std::cout << std::endl << *ft2;
	std::cout << std::endl << *sc0;
	std::cout << std::endl << *sc1;
	std::cout << std::endl << *sc2;
	std::cout << std::endl << *cl0;
	std::cout << std::endl << *cl1;
	std::cout << std::endl << *cl2 << std::endl;

	ft0->meleeAttack("DUMMY-TP");
	ft1->rangedAttack("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	sc0->meleeAttack("DUMMY-TP");
	sc1->rangedAttack("DUMMY-TP");
	sc2->challengeNewcomer();
	std::cout <<std::endl;

	ft0->takeDamage(3);
	ft1->takeDamage(15);
	ft2->takeDamage(110);
	sc0->takeDamage(3);
	sc1->takeDamage(15);
	sc2->takeDamage(110);
	cl0->takeDamage(3);
	cl1->takeDamage(15);
	cl2->takeDamage(110);
	std::cout <<std::endl;

	ft0->beRepaired(3);
	ft1->beRepaired(20);
	ft2->beRepaired(15);
	sc0->beRepaired(3);
	sc1->beRepaired(20);
	sc2->beRepaired(15);
	cl0->beRepaired(3);
	cl1->beRepaired(20);
	cl2->beRepaired(15);
	std::cout <<std::endl;

	ft2->vaulthunter_dot_exe("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	ft2->vaulthunter_dot_exe("DUMMY-TP");
	std::cout <<std::endl;

	delete ft2;
	delete ft1;
	delete ft0;
	delete sc2;
	delete sc1;
	delete sc0;
	delete cl2;
	delete cl1;
	delete cl0;
	return 0;
}