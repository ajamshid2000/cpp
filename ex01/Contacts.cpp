/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:00:57 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/06 16:12:29 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contacts::add_firstname(std::string &firstname)
{
    first_name = firstname;
}

void Contacts::add_lastname(std::string &lastname)
{
    last_name = lastname;
}

void Contacts::add_nickname(std::string &nick_name)
{
    nickname = nick_name;
}

void Contacts::add_phonenumber(std::string &phonenumber)
{
    phone_number = phonenumber;
}

void Contacts::add_darkest_secret(std::string &darkestsecret)
{
    darkest_secret = darkestsecret;
}

std::string Contacts::get_firstname()
{
    return first_name;
}

std::string Contacts::get_lastname()
{
    return last_name;
}

std::string Contacts::get_nickname()
{
    return nickname;
}

std::string Contacts::get_phonenumber()
{
    return phone_number;
}

std::string Contacts::get_darkest_secret()
{
    return darkest_secret;
}
