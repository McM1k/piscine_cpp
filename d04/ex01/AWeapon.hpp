/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:33:18 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 12:33:18 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon {
public:

	AWeapon(AWeapon const &src);
	virtual ~AWeapon(void);
	AWeapon &operator=(AWeapon const &rhs); //equals
	AWeapon(std::string const & name, int apcost, int damage);

	std::string const getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

private:
	AWeapon(void);

protected:
	std::string _name;
	int			_damage;
	int			_APCost;

};

//std::ostream &operator<<(std::ostream &o, AWeapon const &i);


#endif