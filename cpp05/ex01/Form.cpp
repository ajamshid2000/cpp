/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:06:43 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 15:24:10 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), grade_to_exec(150), grade_to_sign(150)
{
    this->is_signed = 0;
}

Form::Form(std::string name_given, int grade_to_exec_given, int grade_to_sign_given) : name(name_given), grade_to_exec(grade_to_exec_given), grade_to_sign(grade_to_sign_given)
{
    this->is_signed = 0;
    if (grade_to_exec_given > 150 || grade_to_sign_given > 150)
        throw Form::GradeTooLowException();
    else if (grade_to_exec_given < 1 || grade_to_sign_given < 1)
        throw Form::GradeTooHighException();
}

Form::~Form()
{
    return;
}

Form::Form(const Form &other) : name(other.name), grade_to_exec(other.grade_to_exec), grade_to_sign(other.grade_to_sign)
{
    *this = other;
}
Form &Form::operator=(const Form &other)
{
    this->is_signed = other.is_signed;
    return (*this);
}

std::string Form::getName() const
{
    return (this->name);
}
bool Form::getIsSigned() const
{
    return (this->is_signed);
}
int Form::getGrade_exec() const
{
    return (this->grade_to_exec);
}
int Form::getGrade_sign() const
{
    return (this->grade_to_sign);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}
const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &str, Form &form)
{
    str << form.getName() << ", signed: ";
    if (form.getIsSigned())
        std::cout << "yes ";
    else
        std::cout << "no ";
    std::cout << ", grade to exectute it: " << form.getGrade_exec() << ", grade to sign it: " << form.getGrade_sign() << std::endl;
    return (str);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGrade_sign())
    {
        if (this->is_signed == 0)
        {
            this->is_signed = 1;
            std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
        }
        else
        {
            std::cout << bureaucrat.getName() << " couldn’t sign " << this->getName() << " becuase form is already signed." << std::endl;
        }
    }
    else
    {
        std::cout << bureaucrat.getName() << " couldn’t sign " << this->getName() << " becuase Grade is too low." << std::endl;
        throw GradeTooLowException();
    }
}
