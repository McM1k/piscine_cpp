/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:07:26 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 13:02:45 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H
# include <iostream>
class Pony{
public:
	Pony(std::string location);
	~Pony();
	void doSomeStuff() const;
private:
	const std::string location;
	std::string favoriteMeal;
	std::string poop;
};

#endif
