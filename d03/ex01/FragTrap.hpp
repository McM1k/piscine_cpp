/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:57:11 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/11 11:57:11 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <sstream>
# include <stdlib.h>
# include <time.h>
# include <iostream>

class FragTrap {
public:
	FragTrap(void);
	FragTrap(FragTrap const &src);
	~FragTrap(void);
	FragTrap &operator=(FragTrap const &rhs); //equals

	FragTrap(std::string name);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);

	unsigned int	getHitPoints() const;
	unsigned int	getMaxHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int 	getMaxEnergyPoints() const;
	unsigned int	getLevel() const;
	std::string		getName() const;
	unsigned int	getMeleeDamage() const;
	unsigned int	getRangedDamage() const;
	unsigned int	getArmorReduction() const;

private:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_meleeDamage;
	unsigned int	_rangedDamage;
	unsigned int	_armorReduction;
	static int		_unassignedNb;

};

std::ostream &operator<<(std::ostream &o, FragTrap const &i);

#endif