/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:38:06 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/16 16:42:33 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    grade = 150;
}

Bureaucrat::Bureaucrat(std::string name_given, int grade_given) : name(name_given)
{
    if (grade_given > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade_given < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade = grade_given;
}

Bureaucrat::~Bureaucrat()
{
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}
int Bureaucrat::getGrade() const
{
    return (this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

void Bureaucrat::increment()
{
    grade--;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrement()
{
    grade++;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::signForm(AForm &aform)
{
    aform.beSigned(*this);
}

std::ostream &operator<<(std::ostream &str, Bureaucrat &bureaucrat)
{
    str << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
    return (str);
}
