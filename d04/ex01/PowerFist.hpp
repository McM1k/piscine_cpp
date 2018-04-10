/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:03:21 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 15:03:21 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include "AWeapon.hpp"
# include <iostream>

class PowerFist : public AWeapon {
public:
	PowerFist(void);
	PowerFist(PowerFist const &src);
	virtual ~PowerFist(void);
	PowerFist &operator=(PowerFist const &rhs); //equals

	void attack() const;

private:

};

//std::ostream &operator<<(std::ostream &o, PowerFist const &i);


#endif