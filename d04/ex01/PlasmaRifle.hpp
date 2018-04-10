/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:03:19 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 15:03:19 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"
# include <iostream>

class PlasmaRifle : public AWeapon {
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &src);
	virtual ~PlasmaRifle(void);
	PlasmaRifle &operator=(PlasmaRifle const &rhs); //equals

	void attack() const;

private:

};

//std::ostream &operator<<(std::ostream &o, PlasmaRifle const &i);


#endif