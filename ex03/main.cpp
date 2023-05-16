/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:28:54 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/16 19:47:55 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		I1;
	AForm		*FormPtr;
	Bureaucrat	B1("Naelle", 1);
	{
		FormPtr = I1.makeForm("shrubbery creation", "Manuel");

		if (FormPtr)
		{
			std::cout << *FormPtr << std::endl;
			B1.signForm(*FormPtr);
			FormPtr->execute(B1);

			delete (FormPtr);
		}
	}

	{
		FormPtr = I1.makeForm("presidential pardon", "Shanley");

		if (FormPtr)
		{
			std::cout << *FormPtr << std::endl;
			B1.signForm(*FormPtr);
			FormPtr->execute(B1);

			delete (FormPtr);
		}
	}

	{

		FormPtr = I1.makeForm("robotomy request", "Shanley");

		if (FormPtr)
		{
			std::cout << *FormPtr << std::endl;
			B1.signForm(*FormPtr);
			FormPtr->execute(B1);

			delete (FormPtr);
		}
	}

	{
		FormPtr = I1.makeForm("fail", "osef");
		if (FormPtr)
		{
			B1.signForm(*FormPtr);
			FormPtr->execute(B1);
			delete (FormPtr);
		}
	}

	return (0);
}
