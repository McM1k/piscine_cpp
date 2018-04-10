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

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap {
public:
	FragTrap(void);
	FragTrap(FragTrap const &src);
	~FragTrap(void);
	FragTrap &operator=(FragTrap const &rhs); //equals

	FragTrap(std::string name);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void vaulthunter_dot_exe(std::string const & target);

private:
	static int		_unassignedNb;
};

#endif