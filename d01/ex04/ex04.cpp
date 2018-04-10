/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:28:31 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 18:28:31 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "STR = " << str << std::endl;
	std::cout << "PTR = " << *ptr << std::endl;
	std::cout << "REF = " << ref << std::endl;
	return (0);
}