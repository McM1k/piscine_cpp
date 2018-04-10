/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:27:35 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 16:27:35 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include <iostream>

class SuperTrap : public NinjaTrap, public FragTrap {
public:
	SuperTrap(void);
	SuperTrap(SuperTrap const &src);
	~SuperTrap(void);
	SuperTrap &operator=(SuperTrap const &rhs); //equals

	SuperTrap(std::string name);
	void meleeAttack(std::string const & target) const;
	void rangedAttack(std::string const & target) const;

private:
	static int		_unassignedNb;
};


#endif