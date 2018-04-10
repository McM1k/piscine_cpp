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
#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"

int main(void) {
	FragTrap *fr0 = new FragTrap();
	FragTrap *fr1 = new FragTrap("P0UL3T");
	FragTrap *fr2 = new FragTrap(*fr1);
	ScavTrap *sc0 = new ScavTrap();
	ScavTrap *sc1 = new ScavTrap("P0UL3T");
	ScavTrap *sc2 = new ScavTrap(*sc1);
	ClapTrap *cl0 = new ClapTrap();
	ClapTrap *cl1 = new ClapTrap("P0UL3T");
	ClapTrap *cl2 = new ClapTrap(*cl1);
	NinjaTrap *ni0 = new NinjaTrap();
	NinjaTrap *ni1 = new NinjaTrap("P0UL3T");
	NinjaTrap *ni2 = new NinjaTrap(*ni1);
	SuperTrap *su0 = new SuperTrap();
	SuperTrap *su1 = new SuperTrap("P0UL3T");
	SuperTrap *su2 = new SuperTrap(*su1);


	std::cout << std::endl << *fr0;
	std::cout << std::endl << *fr1;
	std::cout << std::endl << *fr2;
	std::cout << std::endl << *sc0;
	std::cout << std::endl << *sc1;
	std::cout << std::endl << *sc2;
	std::cout << std::endl << *cl0;
	std::cout << std::endl << *cl1;
	std::cout << std::endl << *cl2;
	std::cout << std::endl << *ni0;
	std::cout << std::endl << *ni1;
	std::cout << std::endl << *ni2;
	std::cout << std::endl << *su0;
	std::cout << std::endl << *su1;
	std::cout << std::endl << *su2 << std::endl;

	fr0->meleeAttack("DUMMY-TP");
	fr1->rangedAttack("DUMMY-TP");
	sc0->meleeAttack("DUMMY-TP");
	sc1->rangedAttack("DUMMY-TP");
	ni0->meleeAttack("DUMMY-TP");
	ni1->rangedAttack("DUMMY-TP");
	su0->meleeAttack("DUMMY-TP");
	su1->rangedAttack("DUMMY-TP");
	std::cout <<std::endl;

	fr0->takeDamage(3);
	fr1->takeDamage(15);
	fr2->takeDamage(110);
	sc0->takeDamage(3);
	sc1->takeDamage(15);
	sc2->takeDamage(110);
	cl0->takeDamage(3);
	cl1->takeDamage(15);
	cl2->takeDamage(110);
	ni0->takeDamage(3);
	ni1->takeDamage(15);
	ni2->takeDamage(110);
	su0->takeDamage(3);
	su1->takeDamage(15);
	su2->takeDamage(110);
	std::cout <<std::endl;

	fr0->beRepaired(3);
	fr1->beRepaired(20);
	fr2->beRepaired(15);
	sc0->beRepaired(3);
	sc1->beRepaired(20);
	sc2->beRepaired(15);
	cl0->beRepaired(3);
	cl1->beRepaired(20);
	cl2->beRepaired(15);
	ni0->beRepaired(3);
	ni1->beRepaired(20);
	ni2->beRepaired(15);
	su0->beRepaired(3);
	su1->beRepaired(20);
	su2->beRepaired(15);
	std::cout <<std::endl;

	fr2->vaulthunter_dot_exe("DUMMY-TP");
	fr2->vaulthunter_dot_exe("DUMMY-TP");
	fr2->vaulthunter_dot_exe("DUMMY-TP");
	fr2->vaulthunter_dot_exe("DUMMY-TP");
	fr2->vaulthunter_dot_exe("DUMMY-TP");
	sc2->challengeNewcomer();
	sc2->challengeNewcomer();
	sc2->challengeNewcomer();
	ni2->ninjaShoebox(*fr0);
	ni2->ninjaShoebox(*sc0);
	ni2->ninjaShoebox(*cl0);
	ni2->ninjaShoebox(*ni0);
	su2->vaulthunter_dot_exe("DUMMY-TP");
	su2->vaulthunter_dot_exe("DUMMY-TP");
	su2->vaulthunter_dot_exe("DUMMY-TP");
	su2->vaulthunter_dot_exe("DUMMY-TP");
	su2->vaulthunter_dot_exe("DUMMY-TP");
	su2->ninjaShoebox(*fr0);
	su2->ninjaShoebox(*sc0);
	su2->ninjaShoebox(*cl0);
	su2->ninjaShoebox(*ni0);
	std::cout <<std::endl;

	delete fr2;
	delete fr1;
	delete fr0;
	delete sc2;
	delete sc1;
	delete sc0;
	delete cl2;
	delete cl1;
	delete cl0;
	delete ni2;
	delete ni1;
	delete ni0;
	delete su2;
	delete su1;
	delete su0;
	return 0;
}