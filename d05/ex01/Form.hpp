/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:21:44 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/15 16:21:44 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form {
public:
	Form(std::string name, int grade);
	virtual ~Form(void);

	std::string	getName() const;
	int			getGrade() const;
	bool		isSigned() const;
	void		isGradeOk(int grade) throw(GradeTooLowException, GradeTooHighException);
	void		setSigned(bool isSigned);

	void		beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException);

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
	bool				_signed;
	int	const			_grade;

	Form(void);
	Form(Form const &src);
	Form &operator=(Form const &rhs); //equals

};

std::ostream &operator<<(std::ostream &o, Form const &i);


#endif