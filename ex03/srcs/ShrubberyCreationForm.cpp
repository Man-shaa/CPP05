/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:21:16 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/16 17:43:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &toCopy) : AForm(toCopy.getName(), toCopy.getGradeSign(), toCopy.getGradeExe()), _target(toCopy._target)
{
	if (this != &toCopy)
		*this = toCopy;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator = (ShrubberyCreationForm &toCopy)
{
	(void)toCopy;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
	std::cout << "Creating " << _target << "_shrubbery ..." << std::endl;

	std::string	outName;
	outName = _target + "_shrubbery";

	std::ofstream	outfile((char *)outName.c_str());
	if (outfile.is_open() == false)
	{
		std::cerr << "Open/Creation outfile failed" << std::endl;
		return ;
	}
	outfile << "      *           *           *           *" << std::endl;
	outfile << "     ***         ***         ***         ***" << std::endl;
	outfile << "    *****       *****       *****       *****" << std::endl;
	outfile << "   *******     *******     *******     *******" << std::endl;
	outfile << "  *********   *********   *********   *********" << std::endl;
	outfile << " *********** *********** *********** ***********" << std::endl;
	outfile << "    |            |            |            |" << std::endl;

	outfile.close();
}
