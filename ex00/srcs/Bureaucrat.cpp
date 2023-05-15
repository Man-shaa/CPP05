/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:45:33 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/15 20:27:50 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(1)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat &toCopy)
{
	if (this != &toCopy)
		*this = toCopy;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

Bureaucrat	&Bureaucrat::operator = (Bureaucrat &toCopy)
{
	_grade = toCopy._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::IncrGrade(void)
{
	if (_grade <= 1)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::DecrGrade(void)
{
	if (_grade >= 150)
		throw (GradeTooLowException());
	_grade++;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception : grade is too low !");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception : grade is too high !");
}

std::ostream	&operator << (std::ostream &o, const Bureaucrat &obj)
{
	o << "Name : " << obj.getName() << std::endl;
	o << "Grade : " << obj.getGrade() << std::endl;
	return (o);
}
