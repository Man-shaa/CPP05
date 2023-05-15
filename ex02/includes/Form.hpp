/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:25:10 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/15 21:43:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	_name;
		bool				_status;
		const int			_gradeSign;
		const int			_gradeExe;

	public:
		Form();
		Form(const std::string name, int gradeSign, int gradeExe);
		Form(Form &toCopy);
		~Form();

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

		Form	&operator = (Form &toCopy);

		std::string	getName(void) const;
		bool		getStatus(void) const;
		int			getGradeSign(void) const;
		int			getGradeExe(void) const;
		
		void		beSigned(Bureaucrat B);

};

std::ostream	&operator << (std::ostream &o, const Form &obj);

#endif
