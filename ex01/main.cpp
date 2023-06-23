/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:28:54 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/23 16:00:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Form	tooHigh("Petition pour virer Shanley", 150, 150);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	// {
	// 	Form		F1("Petition pour virer Shanley le predateur", 149, 150);
	// 	Bureaucrat	B1("Naelle", 3);
	// 	Bureaucrat	Loser("Only a loser", 150);

	// 	std::cout << B1 << std::endl;
	// 	std::cout << F1 << std::endl;

	// 	B1.signForm(F1);

	// 	std::cout << F1 << std::endl;

	// 	Loser.signForm(F1);

	// 	std::cout << F1 << std::endl;
	// }
	return (0);
}
