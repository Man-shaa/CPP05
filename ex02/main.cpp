/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:28:54 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/16 17:48:49 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	// try
	// {
	// 	Bureaucrat	B1("Shanley", 149);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	return (1);
	// }
	Bureaucrat	B1("Shanley", 2);

	{
		PresidentialPardonForm	FormPresident("Manuel");

		std::cout  << B1 << std::endl;
		std::cout << FormPresident << std::endl;

		B1.signForm(FormPresident);
		std::cout << FormPresident << std::endl;

		FormPresident.execute(B1);
	}

	{
		RobotomyRequestForm	RobotomyRq("Manuel");

		std::cout  << B1 << std::endl;
		std::cout << RobotomyRq << std::endl;

		B1.signForm(RobotomyRq);
		std::cout << RobotomyRq << std::endl;

		RobotomyRq.execute(B1);
	}

	{
		ShrubberyCreationForm	Shrub("Manuel");

		std::cout  << B1 << std::endl;
		std::cout << Shrub << std::endl;

		B1.signForm(Shrub);
		std::cout << Shrub << std::endl;

		Shrub.execute(B1);
	}
	
	return (0);
}
