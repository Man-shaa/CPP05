/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:45:47 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/15 21:48:30 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class	Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat &toCopy);
		~Bureaucrat();

		Bureaucrat	&operator = (Bureaucrat &toCopy);

		class GradeTooHighException : public std::exception
		{
			public:
			const char	*what( void ) const throw();
		};
		
		class GradeTooLowException : public	std::exception
		{
			public:
			const char	*what( void ) const throw();
		};

		std::string	getName(void) const;
		int			getGrade(void) const;

		void		IncrGrade(void);
		void		DecrGrade(void);
		void		signForm(Form F);
};

std::ostream	&operator << (std::ostream &o, const Bureaucrat &obj);

#endif