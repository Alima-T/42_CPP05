/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:39:24 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/26 23:44:30 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::beSigned(const Bureaucrat& b)
{
	if(b.getGrade() > m_gradeToSign) throw LowGradeEx();
	else m_isSigned = true;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
	: m_name(name), m_isSigned(false), m_gradeToSign(gradeSign), m_gradeToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw HighGradeEx();
	else if (gradeSign > 150 || gradeExec > 150)
		throw LowGradeEx();
}
const char* AForm::HighGradeEx::what() const throw()
{
	return "AForm Exception: Grade is too high (less than 1)";
}
const char* AForm::LowGradeEx::what() const throw()
{
	return "AForm Exception: Grade is too low (more than 150)";
}
const char* AForm::NotSignedEx::what() const throw()
{
	return "AForm Exception: Form is not signed";
}
void AForm::checkExecution(Bureaucrat const & executor) const
{
	if (!m_isSigned)
		throw NotSignedEx();
	if (executor.getGrade() > m_gradeToExecute)
		throw LowGradeEx();
}
