
#include "PhoneBook.hpp"

int main()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    PhoneBook phone_book;

    while (1)
    {
        std::string command;
        std::cout << "to add a contact type ADD, to search type SEARCH and to exit type  EXIT\n";
        std::cin >> command;
        if (command == "ADD")
        {
            Contacts new_contact;
            std::cout << "please inter first name of the contact\n";
            std::cin >> first_name;
            std::cout << "please inter last name of the contact\n";
            std::cin >> last_name;
            std::cout << "please enter nickname of the contact\n";
            std::cin >> nickname;
            std::cout << "please enter phone numeber of the contact\n";
            std::cin >> phone_number;
            std::cout << "please enter darkest secret of the contact\n";
            std::cin >> darkest_secret;
            new_contact.add_firstname(first_name);
            new_contact.add_lastname(last_name);
            new_contact.add_nickname(nickname);
            new_contact.add_phonenumber(phone_number);
            new_contact.add_darkest_secret(darkest_secret);
            phone_book.add(new_contact);
        }
        if (command == "SEARCH")
        {
            phone_book.search();
        }
        if (command == "EXIT")
        {
            exit(0);
        }
    }
}
