/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:11:32 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/12 20:11:32 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim {
public:
	Victim(std::string name);
	Victim(Victim const &src);
	virtual ~Victim(void);
	Victim &operator=(Victim const &rhs); //equals

	virtual void getPolymorphed() const;

	std::string getName() const;
	void setName(std::string name);

private:
	std::string _name;
	Victim(void);
};
std::ostream &operator<<(std::ostream &o, Victim const &i);

#endif