/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:11:34 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 20:11:34 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"
# include <iostream>

class Peon : public Victim{
public:
	Peon(std::string name);
	Peon(Peon const &src);
	virtual ~Peon(void);
	Peon &operator=(Peon const &rhs); //equals

	virtual void getPolymorphed() const;

private:
	Peon();
};
//std::ostream &operator<<(std::ostream &o, Peon const &i);

#endif