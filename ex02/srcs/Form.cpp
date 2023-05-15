/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:24:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/15 21:22:39 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _status(false), _gradeSign(1), _gradeExe(1)
{
	return ;
}

Form::Form(const std::string name, int gradeSign, int gradeExe) : _name(name), _status(false),_gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (gradeSign < 1 || gradeExe < 1)
		throw (GradeTooHighException());
	else if (gradeSign > 150 || gradeExe > 150)
		throw (GradeTooLowException());
	return ;
}

Form::Form(Form &toCopy) : _name(toCopy._name), _status(toCopy._status), _gradeSign(toCopy._gradeSign), _gradeExe(toCopy._gradeExe)
{
	if (this != &toCopy)
		*this = toCopy;
	return ;
}

Form::~Form(void)
{
	return ;
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Exception : grade is too low !");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Exception : grade is too high !");
}

Form	&Form::operator = (Form &toCopy)
{
	(void)toCopy;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getStatus(void) const
{
	return (_status);
}

int	Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int	Form::getGradeExe(void) const
{
	return (_gradeExe);
}

void		Form::beSigned(Bureaucrat B)
{
	if (B.getGrade() > _gradeSign)
		throw (GradeTooLowException());
	_status = true;
}

std::ostream	&operator << (std::ostream &o, const Form &obj)
{
	o << "Name : " << obj.getName() << std::endl;
	o << "Status : " << obj.getStatus() << std::endl;
	o << "Grade Sign : " << obj.getGradeSign() << std::endl;
	o << "Grade Exec : " << obj.getGradeExe() << std::endl;
	return (o);
}
