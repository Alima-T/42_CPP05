/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:47:38 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 00:19:02 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src), m_target(src.m_target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		m_target = rhs.m_target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	// Проверяем, подписана ли форма и достаточно ли высокий уровень бюрократа
	checkExecution(executor);
    // Создаем файл с именем <target>_shrubbery
    std::ofstream file(m_target + "_shrubbery");
	if(!file)
	{
		std::cerr << "Error: Could not open file " << m_target + "_shrubbery" << std::endl;
		return;
	}
	// file << "ASCII tree 🌳\n";  // настоящие ASCII-деревья
	file << "    *\n";
	file << "   *\n";
    file << "  ***\n";
    file << " *****\n";
    file << "*******\n";
    file << "  |||\n";
    file << "  |||\n";
    file.close();
}
