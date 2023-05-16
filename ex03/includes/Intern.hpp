/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:52:03 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/16 19:25:05 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern &toCopy);
		~Intern();

		Intern	&operator = (Intern &toCopy);

		AForm	*newShrubbery(std::string target);
		AForm	*newPresident(std::string target);
		AForm	*newRobot(std::string target);
		AForm	*makeForm(std::string formName, std::string target);

};

#endif
