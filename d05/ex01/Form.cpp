/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:21:42 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/15 16:21:42 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

/*
 * Constructors
 */
Form::Form(void) : _name("lol"), _grade(2){
	//std::cout << "An instance of Form has been created" << std::endl;
}

Form::Form(Form const &src) : _name("lol"), _grade(2){
	//std::cout << "An instance of Form has been created by copy" << std::endl;
	*this = src;
}

/*
 * Destructors
 */
Form::Form(std::string name, int grade) : _name(name), _signed(false), _grade(grade){
	this->isGradeOk(this->getGrade());
}

/*
 * Destructors
 */
Form::~Form(void) {
	//std::cout << "An instance of Form has been destroyed" << std::endl;
}

/*
 * Getters
 */
std::string Form::getName() const {
	return this->_name;
}

int Form::getGrade() const {
	return this->_grade;
}

bool Form::isSigned() const {
	return this->_signed;
}

/*
 * Setters
 */
void Form::isGradeOk(int grade) throw(GradeTooLowException, GradeTooHighException){
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
}

void Form::setSigned(bool isSigned) {
	this->_signed = isSigned;
}

/*
 * Equals
 */
Form &Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		//this->XXX = rhs.getXXX();
	}
	return *this;
}

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, Form const &i) {
	o << i.getName() << ", Form grade " << i.getGrade() << ", signed = " << i.isSigned() << std::endl;
	return o;
}

/*
 * Other
 */
void Form::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException){
	if (bureaucrat.getGrade() > this->getGrade())
		this->_signed = true;
	else
		throw(GradeTooLowException());
}

/*
 * Exceptions
 */
const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too low.";
}