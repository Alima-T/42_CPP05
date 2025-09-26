/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:50:47 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 01:10:37 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm; // предварительное объявление

class Bureaucrat {
private:
	std::string m_name;
	int m_grade; // 1 (высший) — 150 (низший)

public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat() = default;

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form) const;
	void executeForm(AForm const &form) const;

	// Исключения для Bureaucrat
	class BurHighGradeExc : public std::exception {
		const char* what() const throw();
	};
	class BurLowGradeExc : public std::exception {
		const char* what() const throw();
	};
};

#endif
