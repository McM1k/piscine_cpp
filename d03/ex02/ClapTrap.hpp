/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:52:47 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/11 21:52:47 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
public:
	static std::string intToString(int nb);

	ClapTrap(void);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);
	ClapTrap &operator=(ClapTrap const &rhs); //equals
	ClapTrap(std::string);
	ClapTrap(unsigned int hit, unsigned int maxHit, unsigned int energy,
			 unsigned int maxEnergy, unsigned int level, std::string name,
			 unsigned int melee, unsigned int range, unsigned int armor);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	unsigned int	getHitPoints() const;
	unsigned int	getMaxHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int 	getMaxEnergyPoints() const;
	unsigned int	getLevel() const;
	std::string		getName() const;
	unsigned int	getMeleeDamage() const;
	unsigned int	getRangedDamage() const;
	unsigned int	getArmorReduction() const;

protected:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_meleeDamage;
	unsigned int	_rangedDamage;
	unsigned int	_armorReduction;
private:
	static int		_unassignedNb;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#endif