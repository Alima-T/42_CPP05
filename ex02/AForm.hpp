/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:46:34 by aokhapki          #+#    #+#             */
/*   Updated: 2025/09/26 23:44:13 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>

// virtual const char* what() const throw(); or virtual const char* what() const noexcept;
// what() — это виртуальный метод класса std::exception, возвращает строку с описанием ошибки.
class Bureaucrat;

class AForm {
private:
    std::string m_name;
    bool m_isSigned;
    int m_gradeToSign;
    int m_gradeToExecute;

public:
    AForm(const std::string& name, int gradeSign, int gradeExec);
    virtual ~AForm() = default;

    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;

	void checkExecution(Bureaucrat const & executor) const;
	
    class HighGradeEx : public std::exception {
        const char* what() const throw();
    };
    class LowGradeEx : public std::exception {
        const char* what() const throw();
    };
    class NotSignedEx : public std::exception {
        const char* what() const throw();
    };
};

#endif