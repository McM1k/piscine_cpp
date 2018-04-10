/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:53:04 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 18:53:04 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"
# include <iostream>

class Human{
public:
	Human();
	~Human();
	std::string identify() const;
	const Brain &getBrain() const;
private:
	const Brain brain;
};

#endif
