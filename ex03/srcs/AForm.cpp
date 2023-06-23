/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:24:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/23 16:12:51 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _status(false), _gradeSign(1), _gradeExe(1)
{
	return ;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExe) : _name(name), _status(false),_gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (gradeSign < 1 || gradeExe < 1)
		throw (GradeTooHighException());
	else if (gradeSign > 150 || gradeExe > 150)
		throw (GradeTooLowException());
	return ;
}

AForm::AForm(AForm &toCopy) : _name(toCopy._name), _status(toCopy._status), _gradeSign(toCopy._gradeSign), _gradeExe(toCopy._gradeExe)
{
	if (this != &toCopy)
		*this = toCopy;
	return ;
}

AForm::~AForm(void)
{
	return ;
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Exception : grade is too low !");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Exception : grade is too high !");
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return ("Exception : Form isn't signed !");
}

AForm	&AForm::operator = (AForm &toCopy)
{
	_status = toCopy._status;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getStatus(void) const
{
	return (_status);
}

int	AForm::getGradeSign(void) const
{
	return (_gradeSign);
}

int	AForm::getGradeExe(void) const
{
	return (_gradeExe);
}

void		AForm::beSigned(Bureaucrat B)
{
	if (B.getGrade() > _gradeSign)
		throw (GradeTooLowException());
	_status = true;
}

std::ostream	&operator << (std::ostream &o, const AForm &obj)
{
	o << "Name : " << obj.getName() << std::endl;
	o << "Status : " << obj.getStatus() << std::endl;
	o << "Grade Sign : " << obj.getGradeSign() << std::endl;
	o << "Grade Exec : " << obj.getGradeExe() << std::endl;
	return (o);
}

void	AForm::checkExec(Bureaucrat const &executor) const
{
	if (_status == false)
		throw (FormNotSigned());
	if (_gradeExe < executor.getGrade())
		throw (GradeTooLowException());
}
