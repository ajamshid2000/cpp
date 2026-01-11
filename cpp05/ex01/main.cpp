/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:53:00 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/18 15:24:10 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Valid Form Creation ===" << std::endl;
    try
    {
        Form f1("TaxForm", 100, 120);
        std::cout << f1.getName() << " created successfully." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error creating form: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Form Creation (Grade Too High) ===" << std::endl;
    try
    {
        Form f2("SecretForm", 0, 50); // Invalid: grade too high (must be >= 1)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Form Creation (Grade Too Low) ===" << std::endl;
    try
    {
        Form f3("SimpleForm", 151, 150); // Invalid: grade too low (> 150)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat Signing a Form ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 50);
        Form permit("Permit", 30, 60); // Needs grade 60 to sign

        alice.signForm(permit); // Should succeed
        alice.signForm(permit); // already signed
        std::cout << permit.getName() << " signed: " << (permit.getIsSigned() ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Signing failed: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat With Too Low Grade to Sign ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 100);
        Form classified("Classified", 20, 90); // Needs grade 90 to sign

        bob.signForm(classified); // Should throw
        std::cout << classified.getName() << " signed: " << (classified.getIsSigned() ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught while signing: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowBoundary("LowBoundary", 150);
        std::cout << lowBoundary << std::endl;

        Bureaucrat highBoundary("HighBoundary", 1);
        std::cout << highBoundary << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat tooLow("TooLow", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught too low grade: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught too high grade: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat inc("Incrementer", 2);
        std::cout << inc << std::endl;
        inc.increment(); // Goes to 1 (highest)
        std::cout << "After increment: " << inc << std::endl;
        inc.increment(); // Should throw GradeTooHighException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Increment exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat dec("Decrementer", 149);
        std::cout << dec << std::endl;
        dec.decrement(); // Goes to 150 (lowest)
        std::cout << "After decrement: " << dec << std::endl;
        dec.decrement(); // Should throw GradeTooLowException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Decrement exception: " << e.what() << std::endl;
    }

    Form edgeForm("EdgeCaseForm", 50, 50);
    Bureaucrat signerExact("ExactSigner", 50);
    Bureaucrat signerLower("LowerSigner", 51);

    try
    {
        signerExact.signForm(edgeForm);
        std::cout << edgeForm.getName() << " signed status: " << (edgeForm.getIsSigned() ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "ExactSigner error: " << e.what() << std::endl;
    }

    try
    {
        signerLower.signForm(edgeForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "LowerSigner error: " << e.what() << std::endl;
    }
    return 0;
}