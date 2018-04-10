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
	//test exceptions constructeur bureaucrat
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

	//test exceptions constructeur form
	Form *f1;
	Form *f0;
	try {
		f0 = new Form("poulet", 2);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		delete f0;
	}
	try {
		f1 = new Form("poulet", 3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		delete f1;
	}
	try {
		Form f2("poulet", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f3("poulet", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	//test singing exception
	b1->signForm(*f1);
	b1->signForm(*f0);

	//test exception incrementations
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