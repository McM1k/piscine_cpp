/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:45:53 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 13:45:53 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class NinjaTrap : public ClapTrap {
public:
	NinjaTrap(void);
	NinjaTrap(NinjaTrap const &src);
	~NinjaTrap(void);
	NinjaTrap &operator=(NinjaTrap const &rhs); //equals

	NinjaTrap(std::string name);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void ninjaShoebox(FragTrap &fr);
	void ninjaShoebox(ScavTrap &sc);
	void ninjaShoebox(ClapTrap &cl);
	void ninjaShoebox(NinjaTrap &ni);

private:
	static int		_unassignedNb;
};

#endif