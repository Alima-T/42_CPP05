/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:50:41 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 01:10:31 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

// ===================== Конструктор =====================
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: m_name(name), m_grade(grade) 
{
	if (m_grade < 1)
		throw BurHighGradeExc();
	if (m_grade > 150)
		throw BurLowGradeExc();
}

// ===================== Геттеры =====================
const std::string& Bureaucrat::getName() const 
{
	return m_name;
}

int Bureaucrat::getGrade() const {
	return m_grade;
}

void Bureaucrat::incrementGrade() 
{
	if (m_grade <= 1)
		throw BurHighGradeExc();
	--m_grade;
}

void Bureaucrat::decrementGrade() 
{
	if (m_grade >= 150)
		throw BurLowGradeExc();
	++m_grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm &form) const 
{
	try {
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << m_name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);  // вызывает execute конкретной формы
		std::cout << m_name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << m_name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::BurHighGradeExc::what() const throw() {
	return "Bureaucrat grade is too high!";
}

const char* Bureaucrat::BurLowGradeExc::what() const throw() {
	return "Bureaucrat grade is too low!";
}
