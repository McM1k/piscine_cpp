/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:37:55 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 16:37:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D01_ZOMBIEHORDE_HPP
# define D01_ZOMBIEHORDE_HPP
# include "Zombie.hpp"

class ZombieHorde{
public:
	ZombieHorde(int n, std::string type);
	~ZombieHorde();
	void announce() const;
private:
	const int	n;
	Zombie		*horde;
};
#endif
