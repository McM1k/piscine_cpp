/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:55:55 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 19:55:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include "Enemy.hpp"
# include <iostream>

class SuperMutant : public Enemy {
public:
	SuperMutant(void);
	virtual ~SuperMutant(void);
	SuperMutant &operator=(SuperMutant const &rhs); //equals
	void takeDamage(int value);

private:
	SuperMutant(SuperMutant const &src);

};

//std::ostream &operator<<(std::ostream &o, SuperMutant const &i);


#endif