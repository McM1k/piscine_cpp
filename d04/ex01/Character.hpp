/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:18:02 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 20:18:02 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <iostream>

class Character {
public:
	virtual ~Character(void);
	Character &operator=(Character const &rhs); //equals
	Character(std::string const & name);

	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);
	std::string getName() const;
	int getAP() const;
	AWeapon *getWeapon() const;

protected:
	std::string	_name;
	int			_AP;
	AWeapon		*_weapon;

private:
	Character(void);
	Character(Character const &src);

};

std::ostream &operator<<(std::ostream &o, Character const &i);


#endif