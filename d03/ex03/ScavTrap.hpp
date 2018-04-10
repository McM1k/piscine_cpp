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
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap{
public:
	ScavTrap(void);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &rhs); //equals

	ScavTrap(std::string name);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void challengeNewcomer(void);

private:
	static int		_unassignedNb;
};

#endif