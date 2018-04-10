/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:13:30 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/13 17:13:30 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy {
public:
	virtual ~Enemy(void);
	Enemy &operator=(Enemy const &rhs); //equals
	Enemy(int hp, std::string const & type);

	std::string virtual getType() const;
	int getHP() const;
	virtual void takeDamage(int value);

protected:
	int			_hp;
	std::string	_type;
	Enemy(void);

private:

	Enemy(Enemy const &src);

};

std::ostream &operator<<(std::ostream &o, Enemy const &i);

#endif