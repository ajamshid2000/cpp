/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:19:38 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/16 16:13:47 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP
#include <iostream>
#include <string.h>
#include "Form.hpp"
class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name_given, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    std::string getName() const;
    int getGrade() const;

    void increment();
    void decrement();
    void signForm(Form &form);

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
};

std::ostream &operator<<(std::ostream &str, Bureaucrat &bureaucrat);

#endif
