/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:06:10 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/11 21:06:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap {
public:
	ScavTrap(void);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &rhs); //equals

	ScavTrap(std::string name);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void);
	std::string intToString(int nb);

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

std::ostream &operator<<(std::ostream &o, ScavTrap const &i);

#endif