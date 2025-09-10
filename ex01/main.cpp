/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:04:00 by aokhapki          #+#    #+#             */
/*   Updated: 2025/08/29 15:37:18 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 20);

        Form taxForm("Tax Form", 45, 30);
        Form permitForm("Permit Form", 10, 5);

        std::cout << taxForm << std::endl;
        std::cout << permitForm << std::endl;

        // Попытка подписать форму бюрократом с низким уровнем
        alice.signForm(taxForm); // должно не сработать
        // Попытка подписать форму бюрократом с высоким уровнем
        bob.signForm(taxForm);   // должно сработать

        std::cout << taxForm << std::endl;

        // Проверяем исключение при слишком высокой форме
        alice.signForm(permitForm); // не хватит grade
        bob.signForm(permitForm);   // должно сработать

        std::cout << permitForm << std::endl;

        // Попытка создать форму с неправильным grade
        Form invalidForm("Invalid", 0, 151); // выбросит исключение
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
