/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:46:51 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/15 12:46:51 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "Form.hpp"
# include <iostream>

class Form;

class Bureaucrat {
public:
	Bureaucrat(std::string name, int grade);
	virtual ~Bureaucrat(void);

	std::string	getName() const;
	int			getGrade() const;
	void		setGrade(int grade) throw(GradeTooLowException, GradeTooHighException);

	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const	_name;
	int					_grade;

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs); //equals

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif