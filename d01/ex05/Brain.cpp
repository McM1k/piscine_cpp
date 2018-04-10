/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:54:38 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 18:54:38 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {

}

Brain::~Brain() {

}

std::string Brain::identify() const{
	std::stringstream ss;
	ss << this;
	std::string str = ss.str();
	size_t i = 0;
	while (i < str.size()){
		str[i] = std::toupper(str[i]);
		i++;
	}
	if (str.size() > 1)
		str[1] = std::tolower(str[1]);
	return str;
}