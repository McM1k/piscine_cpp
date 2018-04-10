/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:46:54 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/15 12:46:54 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/*
 * Constructors
 */
Bureaucrat::Bureaucrat(void) {
	//std::cout << "An instance of Bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	//std::cout << "An instance of Bureaucrat has been created by copy" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	setGrade(grade);
}

/*
 * Destructors
 */
Bureaucrat::~Bureaucrat(void) {
	//std::cout << "An instance of Bureaucrat has been destroyed" << std::endl;
}

/*
 * Getters
 */
std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

/*
 * Setters
 */
void Bureaucrat::setGrade(int grade) throw(GradeTooLowException, GradeTooHighException){
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	else
		this->_grade = grade;
}

/*
 * Equals
 */
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		//this->XXX = rhs.getXXX();
	}
	return *this;
}

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

/*
 * Other
 */
void Bureaucrat::incrementGrade() {
	setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade() {
	setGrade(this->getGrade() + 1);
}

/*
 * Exceptions
 */
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade max is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade min is 150.";
}