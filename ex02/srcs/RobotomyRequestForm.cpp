/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:29:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/16 17:02:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &toCopy) : AForm(toCopy.getName(), toCopy.getGradeSign(), toCopy.getGradeExe()), _target(toCopy._target)
{
	if (this != &toCopy)
		*this = toCopy;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator = (RobotomyRequestForm &toCopy)
{
	(void)toCopy;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkExec(executor);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	srand(time(NULL));
	int randomNbr = rand() % 2;
	if (randomNbr == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " has failed to be robotomized" << std::endl;
}
