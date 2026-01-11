/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:57:20 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 15:24:10 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int grade_to_exec;
    const int grade_to_sign;

public:
    Form();
    Form(std::string name_given, int grade_to_exec_given, int grade_to_sign_given);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    std::string getName() const;
    bool getIsSigned() const;
    int getGrade_exec() const;
    int getGrade_sign() const;

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

    void beSigned(Bureaucrat bureaucrat);
};

std::ostream &operator<<(std::ostream &str, Form &form);

#endif
