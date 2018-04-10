/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:07:23 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 20:07:23 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include "Enemy.hpp"
# include <iostream>

class RadScorpion : public Enemy {
public:
	RadScorpion(void);
	virtual ~RadScorpion(void);
	RadScorpion &operator=(RadScorpion const &rhs); //equals


private:
	RadScorpion(RadScorpion const &src);

};

//std::ostream &operator<<(std::ostream &o, RadScorpion const &i);


#endif