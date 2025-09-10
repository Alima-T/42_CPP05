/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:14:14 by aokhapki          #+#    #+#             */
/*   Updated: 2025/08/29 15:35:03 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): m_name("Default"), 
			m_isSigned(false), 
			m_gradeToSign(150), 
			m_gradeToExecute(150) {}	

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : m_name(name), 
	m_isSigned(false), 
	m_gradeToSign(gradeToSign), 
	m_gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw std::runtime_error("Grade too high!");
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw std::runtime_error("Grade too low!");
}

Form::Form(const Form &other)
    : m_name(other.m_name), 
	m_isSigned(other.m_isSigned), 
	m_gradeToSign(other.m_gradeToSign), 
	m_gradeToExecute(other.m_gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        m_isSigned = other.m_isSigned; // Изменяется только статус подписания
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return m_name; }
bool Form::isSigned() const { return m_isSigned; }
int Form::getGradeToSign() const { return m_gradeToSign; }
int Form::getGradeToExecute() const { return m_gradeToExecute; }

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > m_gradeToSign)
        throw std::runtime_error("Bureaucrat grade too low to sign");
    m_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName()
       << " [signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute() << "]";
    return os;
}
