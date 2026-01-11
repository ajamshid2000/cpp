/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:06:43 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 15:25:33 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), grade_to_exec(150), grade_to_sign(150)
{
    this->is_signed = 0;
}

AForm::AForm(std::string name_given, int grade_to_exec_given, int grade_to_sign_given) : name(name_given), grade_to_exec(grade_to_exec_given), grade_to_sign(grade_to_sign_given)
{
    this->is_signed = 0;
    if (grade_to_exec_given > 150 || grade_to_sign_given > 150)
        throw AForm::GradeTooLowException();
    else if (grade_to_exec_given < 1 || grade_to_sign_given < 1)
        throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
    return;
}

AForm::AForm(const AForm &other) : name(other.name), grade_to_exec(other.grade_to_exec), grade_to_sign(other.grade_to_sign)
{
    *this = other;
}
AForm &AForm::operator=(const AForm &other)
{
    this->is_signed = other.is_signed;
    return (*this);
}

std::string AForm::getName() const
{
    return (this->name);
}
bool AForm::getIsSigned() const
{
    return (this->is_signed);
}
int AForm::getGradeExec() const
{
    return (this->grade_to_exec);
}
int AForm::getGradeSign() const
{
    return (this->grade_to_sign);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form Not Signed!";
}

std::ostream &operator<<(std::ostream &str, AForm &aform)
{
    str << aform.getName() << ", signed: ";
    if (aform.getIsSigned())
        std::cout << "yes ";
    else
        std::cout << "no ";
    std::cout << ", grade to exectute it: " << aform.getGradeExec() << ", grade to sign it: " << aform.getGradeSign() << std::endl;
    return (str);
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeSign())
    {
        if (this->is_signed == 0)
        {
            this->is_signed = 1;
            std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
        }
        else
        {
            std::cout << bureaucrat.getName() << " couldn’t sign " << this->getName() << " becuase aform is already signed." << std::endl;
        }
    }
    else
    {
        std::cout << bureaucrat.getName() << " couldn’t sign " << this->getName() << " becuase Grade is too low." << std::endl;
        throw GradeTooLowException();
    }
}
