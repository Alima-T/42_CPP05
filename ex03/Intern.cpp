/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:02:18 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 01:09:42 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& src) { (void)src; }
Intern& Intern::operator=(const Intern& rhs) 
{
	(void)rhs;
	return *this;
}
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) 
{
	// Array of forms
	const std::string names[3] = { "shrubbery creation",
									"robotomy request",
									"presidential pardon"
								};
	// Array of creation functions
	typedef AForm* (*FormCreator)(const std::string& target);

	FormCreator creators[3] = {
		[](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); },
		[](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); },
		[](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); }
	};

	// Search for the form name and create the corresponding form
	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cerr << "Error: Form \"" << formName << "\" does not exist" << std::endl;
	return nullptr;
}
