/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:15:51 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 00:19:23 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), m_target(src.m_target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) 
{
    if (this != &rhs) 
	{
        AForm::operator=(rhs);
        m_target = rhs.m_target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
    checkExecution(executor);
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox\n";
}
