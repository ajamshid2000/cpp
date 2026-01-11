/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:53:00 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 17:25:10 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void test_form(AForm &form, Bureaucrat &signer, Bureaucrat &executor)
{
    std::cout << "\n--- Testing form: " << form.getName() << " ---\n";

    try {
        std::cout << "[1] Trying to execute before signing...\n";
        form.execute(executor);
    } catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "[2] Signing with: " << signer.getName() << std::endl;
        form.beSigned(signer);
        std::cout << "Form signed.\n";
    } catch (const std::exception &e) {
        std::cout << "Signing failed: " << e.what() << std::endl;
    }

    try {
        std::cout << "[3] Executing with: " << executor.getName() << std::endl;
        form.execute(executor);
        std::cout << "Execution successful.\n";
    } catch (const std::exception &e) {
        std::cout << "Execution failed: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------\n";
}

int main()
{
    std::cout << "=== Creating Bureaucrats ===\n";
    Bureaucrat low("Low", 150);
    Bureaucrat mid("Mid", 70);
    Bureaucrat high("High", 1);

    std::cout << "\n=== Creating Forms ===\n";
    ShrubberyCreationForm shrub("Garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n=== Running Form Tests ===\n";

    test_form(shrub, mid, mid);     // Should pass (70 < 145, 137)
    test_form(robo, mid, mid);      // Should pass (70 < 72, 45)
    test_form(pardon, mid, high);   // Should fail signing (mid grade too low)

    std::cout << "\n=== Trying with High Rank for Presidential Pardon ===\n";
    test_form(pardon, high, high);  // Should pass

    std::cout << "\n=== Testing invalid signing ===\n";
    try {
        ShrubberyCreationForm bad("Bush");
        bad.beSigned(low); // Too low to sign
    } catch (const std::exception &e) {
        std::cout << "Low couldn't sign: " << e.what() << std::endl;
    }

    return 0;
}

