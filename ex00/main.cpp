/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:43:19 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/15 18:48:32 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		Bureaucrat	John("John", 1);

		std::cout << John << std::endl;
		try
		{
			John.IncrGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
		std::cout << John << std::endl;
	}

	// {
	// 	Bureaucrat	John("John", 150);

	// 	std::cout << John << std::endl;
	// 	try
	// 	{
	// 		John.DecrGrade();
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 		return (2);
	// 	}
	// 	std::cout << John << std::endl;
	// }

	// {
	// 	Bureaucrat	John("John", 5);
	// 	std::cout << John << std::endl;
	// 	try
	// 	{
	// 		John.IncrGrade();
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 		return (3);
	// 	}
	// 	std::cout << John << std::endl;
	// 	try
	// 	{
	// 		John.DecrGrade();
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 		return (4);
	// 	}
	// 	std::cout << John << std::endl;
	// }

	// {
	// 	try
	// 	{
	// 		Bureaucrat	tooHigh("Shanley", -3);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 		return (5);
	// 	}
	// }
	return (0);
}
