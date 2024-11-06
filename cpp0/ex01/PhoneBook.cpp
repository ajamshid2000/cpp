/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:00:57 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/06 16:27:02 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    number_of_contacts = 0;
}

void PhoneBook::add(Contacts contact)
{
    int i = 0;
    while (number_of_contacts == 8 && i < 7)
    {
        contact_list[i] = contact_list[i + 1];
        if (i == 6)
            number_of_contacts = 7;
        i++;
    }
    contact_list[number_of_contacts] = contact;
    number_of_contacts++;
}

void PhoneBook::search()
{
    int i = 0;
    int index;
    std::cout << "     index|first name| last name|  nickname\n";
    while (i < number_of_contacts)
    {
        std::cout << std::setw(10) << i << "|";
        if (contact_list[i].get_firstname().length() > 10)
            std::cout << std::setw(9) << contact_list[i].get_firstname().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contact_list[i].get_firstname() << "|";
        if (contact_list[i].get_lastname().length() > 10)
            std::cout << std::setw(9) << contact_list[i].get_lastname().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << contact_list[i].get_lastname() << "|";
        if (contact_list[i].get_nickname().length() > 10)
            std::cout << std::setw(9) << contact_list[i].get_nickname().substr(0, 9) << std::endl;
        else
            std::cout << std::setw(10) << contact_list[i].get_nickname() << std::endl;
        i++;
    }
    std::cout << "please enter the index of the contact that you want to see\n";
    std::cin >> index;
    if (std::cin.fail())
    {
        std::cout << "yout have entered invalid index\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    else if (index < number_of_contacts && index >= 0)
        std::cout << contact_list[index].get_firstname() << "\n"
                  << contact_list[index].get_lastname() << "\n"
                  << contact_list[index].get_nickname() << "\n"
                  << contact_list[index].get_phonenumber() << "\n"
                  << contact_list[index].get_darkest_secret() << "\n";
    else
        std::cout << "the index number is out of range\n";
}
