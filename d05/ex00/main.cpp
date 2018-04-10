/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:46:49 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/15 12:46:49 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat *b1;
	try {
		b1 = new Bureaucrat("poulet", 3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		delete b1;
	}
	try {
		Bureaucrat b2("poulet", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b3("poulet", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << *b1;
	try {
		b1->incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *b1;
	try {
		b1->incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *b1;
	try {
		b1->incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *b1;
	delete b1;
}