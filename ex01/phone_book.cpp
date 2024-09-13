
#include <iostream>
#include <iomanip>

class contacts
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        void add_firstname(std::string &firstname){
            first_name = firstname;}
        void add_lastname(std::string &lastname){
            last_name = lastname;}
        void add_nickname(std::string &nick_name){
            nickname = nick_name;}
        void add_phonenumber(std::string &phonenumber){
            phone_number = phonenumber;}
        void add_darkest_secret(std::string &darkestsecret){
            darkest_secret = darkestsecret;}
        std::string get_firstname() {
            return first_name;}
        std::string get_lastname(){
            return last_name;}
        std::string get_nickname(){
            return nickname;}
        std::string get_phonenumber(){
            return phone_number;}
        std::string get_darkest_secret(){
            return darkest_secret;}

};


class phonebook
{
    private:
        int number_of_contacts = 0;
        contacts contact_list[8];
    public:
        void add(contacts contact){
            int i = 0;
            while(number_of_contacts == 8 && i < 7){
                contact_list[i] = contact_list[i+1];
                if(i == 6)
                    number_of_contacts = 7;
                i++;
            }
            contact_list[number_of_contacts] = contact; 
            number_of_contacts++;
            
        }
        void search(){
            int i = 0;
            int index;
            std::cout << "     index|first name| last name|  nickname\n";
            while(i < number_of_contacts)
            {
                std::cout << std::setw(10) << i << "|";
                if(contact_list[i].get_firstname().length() > 10)
                    std::cout << std::setw(9) << contact_list[i].get_firstname().substr(0, 9) << ".|";
                else
                    std::cout << std::setw(10) << contact_list[i].get_firstname() << "|";
                if(contact_list[i].get_lastname().length() > 10)
                    std::cout << std::setw(9) << contact_list[i].get_lastname().substr(0, 9) << ".|";
                else
                    std::cout << std::setw(10) << contact_list[i].get_lastname() << "|";
                if(contact_list[i].get_nickname().length() > 10)
                    std::cout << std::setw(9) << contact_list[i].get_nickname().substr(0, 9) << ".|";
                else
                    std::cout << std::setw(10) << contact_list[i].get_nickname() << "\n";
                i++;
            }
            std::cout << "please enter the index of the contact that you want to see\n";
            std::cin >> index;
            if(std::cin.fail())
            {
                std::cout << "yout have entered invalid index\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            else if(index < number_of_contacts)
                std::cout << contact_list[index].get_firstname() << "\n" << contact_list[index].get_lastname() << "\n" << contact_list[index].get_nickname() << "\n" << contact_list[index].get_phonenumber() << "\n" << contact_list[index].get_darkest_secret() << "\n";
            else
            std::cout << "the index number is out of range\n";
        }
        void exit(){std::exit(0);}
    

};

int main()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    phonebook phone_book;

    while(1)
    {
        std::string command;
        std::cout << "to add a contact type ADD, to search type SEARCH and to exit type  EXIT\n";
        std::cin >> command;
        if(command == "ADD")
        {
            contacts new_contact;
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
        if(command == "SEARCH")
        {
            phone_book.search();
        }
        if(command == "EXIT")
        {
            phone_book.exit();
        }

    }
}

