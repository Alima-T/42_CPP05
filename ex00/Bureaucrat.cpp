/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:50:41 by aokhapki          #+#    #+#             */
/*   Updated: 2025/08/29 14:44:33 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>


Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : m_name(name), m_grade(grade)
{
    if (grade < 1)
        throw std::out_of_range("Grade is too high (less than 1)");
    else if (grade > 150)
        throw std::out_of_range("Grade is too low (more than 150)");
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : m_name(src.m_name), m_grade(src.m_grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if(this != &rhs)
	{
		this->m_grade = rhs.m_grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {};

// getters and setters
std::string Bureaucrat::getName() const
{
	return m_name;
}
int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::incrementGrade()
{
    if (m_grade - 1 < 1)
        throw std::out_of_range("Cannot increment: grade would be too high");
    m_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (m_grade + 1 > 150)
        throw std::out_of_range("Cannot decrement: grade would be too low");
    m_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}