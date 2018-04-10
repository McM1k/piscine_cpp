/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:56:33 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 13:56:33 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"
#include <iostream>

class ZombieEvent {
public:
	static void setZombieType(std::string type);
	static Zombie *newZombie(std::string name);
	static Zombie *randomChump();
private:
	static std::string _type;
};

#endif