/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:20:24 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 01:10:42 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>   // для rand()
#include <ctime>     // для srand()
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	// Инициализация генератора случайных чисел
	srand(static_cast<unsigned int>(time(NULL)));

	try {
		Bureaucrat bob("Bob", 40);
		Bureaucrat alice("Alice", 5);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("home");
		PresidentialPardonForm pardon("home");

		// Подписываем формы
		shrub.beSigned(bob);
		robot.beSigned(bob);
		pardon.beSigned(alice);

		// Выполняем формы
		bob.executeForm(shrub);    // должно работать
		bob.executeForm(robot);    // 50% успеха
		alice.executeForm(pardon); // должно работать

		// Попытка выполнить форму с недостаточным рангом
		bob.executeForm(pardon);   // выбросит LowGrade

	} catch (std::exception &e) {
		std::cout << "Ошибка: " << e.what() << std::endl;
	}

	return 0;
}
