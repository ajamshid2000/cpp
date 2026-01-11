/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:38 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 17:19:35 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default ShrubberyCreationForm", 145, 137), target("default ShrubberyCreationForm")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target_given): AForm(target_given, 145, 137), target(target_given)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (!outfile)
        throw std::runtime_error("Could not create output file");

    outfile << "   /\\      /\\   " << std::endl;
    outfile << "  /  \\    /  \\  " << std::endl;
    outfile << " /_  _\\  /_  _\\ " << std::endl;
    outfile << "   ||      ||    " << std::endl;

    outfile.close();
}