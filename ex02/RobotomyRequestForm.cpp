/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:57:25 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/27 01:10:57 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>   // для rand()
#include <ctime>     // для srand()

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), m_target(src.m_target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) 
{
	if (this != &rhs) 
	{
		AForm::operator=(rhs);
		m_target = rhs.m_target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
1.rand() — функция из <cstdlib>, которая возвращает случайное целое число.
Проблема: без установки "зерна" (seed) rand() всегда генерирует один и тот же набор чисел при каждом запуске программы.
srand(seed) — устанавливает начальное значение генератора случайных чисел. После этого rand() будет выдавать разные числа каждый раз, если seed меняется.
2.time(NULL) возвращает текущее время в секундах с 1 января 1970 года (UNIX-время).
Значение постоянно меняется, поэтому его можно использовать как seed, чтобы генератор выдавал разные числа при каждом запуске программы.
3.static_cast<unsigned int>(...)
time(NULL) возвращает значение типа time_t (это может быть long или другой тип).
srand() требует аргумент типа unsigned int.
static_cast<unsigned int>(...) превращает time_t в unsigned int.
Берём текущее время в секундах,
Преобразуем в unsigned int,
Устанавливаем как seed генератора случайных чисел.
*/
void RobotomyRequestForm::execute(Bureaucrat const &executor) const 
{
	checkExecution(executor);
	std::cout << "Bzzzzzz... drilling noises...\n";
	// инициализация генератора случайных чисел (один раз в программе!)
	static bool seeded = false;
	if (!seeded) {
		srand(static_cast<unsigned int>(time(NULL)));
		seeded = true;
	}
	if (rand() % 2) // 50% of the time
		std::cout << m_target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed for " << m_target << "\n";
}
