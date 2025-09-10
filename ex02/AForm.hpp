/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:46:34 by aokhapki          #+#    #+#             */
/*   Updated: 2025/08/31 00:39:27 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
    std::string name;
    bool isSigned;
    int gradeToSign;
    int gradeToExecute;

public:
    AForm(const std::string& name, int gradeSign, int gradeExec);
    virtual ~AForm() = default;

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& b);

    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
        const char* what() const throw();
    };
};

#endif