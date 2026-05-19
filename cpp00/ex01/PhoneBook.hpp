/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:58:54 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/06 16:05:52 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>
#include <stdlib.h>
#include <iomanip>

class Contacts
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void add_firstname(std::string &firstname);
    void add_lastname(std::string &lastname);
    void add_nickname(std::string &nick_name);
    void add_phonenumber(std::string &phonenumber);
    void add_darkest_secret(std::string &darkestsecret);
    std::string get_firstname();
    std::string get_lastname();
    std::string get_nickname();
    std::string get_phonenumber();
    std::string get_darkest_secret();
};

class PhoneBook
{
private:
    int number_of_contacts;
    Contacts contact_list[8];

public:
    PhoneBook(void);
    void add(Contacts contact);
    void search();
};

#endif