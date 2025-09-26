/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:20:24 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 01:09:28 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

int main() {
	Intern someRandomIntern;
	AForm* form;

	// Попробуем создать RobotomyRequestForm
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form) {
		delete form; // не забывай освобождать память
	}

	// Попробуем создать ShrubberyCreationForm
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	if (form) {
		delete form;
	}

	// Попробуем создать PresidentialPardonForm
	form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (form) {
		delete form;
	}

	// Ошибка: такой формы нет
	form = someRandomIntern.makeForm("coffee request", "Intern");
	if (form) {
		delete form;
	}

	return 0;
}
