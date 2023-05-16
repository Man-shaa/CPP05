/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:25:10 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/16 16:31:50 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	AForm
{
	private:
		const std::string	_name;
		bool				_status;
		const int			_gradeSign;
		const int			_gradeExe;

	public:
		AForm();
		AForm(const std::string name, int gradeSign, int gradeExe);
		AForm(AForm &toCopy);
		virtual ~AForm();

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

		class FormNotSigned : public std::exception
		{
			public:
			const char	*what( void ) const throw();
		};

		AForm	&operator = (AForm &toCopy);

		std::string		getName(void) const;
		bool			getStatus(void) const;
		int				getGradeSign(void) const;
		int				getGradeExe(void) const;

		virtual void	beSigned(Bureaucrat B);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void			checkExec(Bureaucrat const &executor) const;

};

std::ostream	&operator << (std::ostream &o, const AForm &obj);

#endif
