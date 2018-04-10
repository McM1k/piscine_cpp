/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:11:30 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 20:11:30 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
#include "Victim.hpp"
# include <iostream>

class Sorcerer {
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const &src);
	virtual ~Sorcerer(void);
	Sorcerer &operator=(Sorcerer const &rhs); //equals

	void polymorph(Victim const &victim) const;

	std::string getName() const;
	std::string getTitle() const;

private:
	std::string	_name;
	std::string	_title;
	Sorcerer(void);

};

std::ostream &operator<<(std::ostream &o, Sorcerer const &i);

#endif