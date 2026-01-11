/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:31 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 15:25:33 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool is_signed;
    const int grade_to_exec;
    const int grade_to_sign;

public:
    AForm();
    AForm(std::string name_given, int grade_to_exec_given, int grade_to_sign_given);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeExec() const;
    int getGradeSign() const;

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw(); // here it is overriding the original from exception lass;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw(); // here too
    };
    
    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw(); // here too
    };

    void beSigned(Bureaucrat bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &str, AForm &aform);

#endif