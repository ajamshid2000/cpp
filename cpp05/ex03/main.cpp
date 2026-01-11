/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:53:00 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 17:34:03 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{

    Intern intern;
    AForm *form;

    form = intern.makeForm("robotomy request", "Bender");
    if (form)
    {
        Bureaucrat b("Bob", 1);
        try
        {
            form->beSigned(b);
            form->execute(b);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
    }
    form = intern.makeForm("shrubbery creation", "Garden");
    if (form)
    {
        Bureaucrat b("Bob", 1);
        try
        {
            form->beSigned(b);
            form->execute(b);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
    }
    form = intern.makeForm("presidential pardon", "Mark");
    if (form)
    {
        Bureaucrat b("Bob", 1);
        try
        {
            form->beSigned(b);
            form->execute(b);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        delete form;
    }
    form = intern.makeForm("Unknown form", "Mark");
    return 0;
}