/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:08:33 by ajamshid          #+#    #+#             */
/*   Updated: 2025/06/03 12:09:20 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <limits>

int is_all_digits(std::string str)
{
    int point_found = 0;
    for (std::string::iterator begin = str.begin(); begin != str.end(); begin++)
    {
        if (!std::isdigit(*begin))
        {
            if (*begin == '.' && point_found == 0)
            {
                point_found = 1;
                continue;
            }
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cout << "Error: too many arguments" << std::endl;
        return 1;
    }
    if (argc == 1)
    {
        std::cout << "Error: could not open file" << std::endl;
        return 1;
    }
    std::ifstream infile(argv[1]);
    if (!infile)
    {
        std::cout << "could not open " << argv[1] << std::endl;
        return 1;
    }
    std::string date, amount, line;
    std::getline(infile, line);
    if (line != "date | value")
    {
        std::cout << "first line should be 'date | value'" << std::endl;
        return 1;
    }

    BitcoinExchange B;
    float value;

    try
    {
        while (std::getline(infile, line))
        {
            if (line.find(" | ") == std::string::npos)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            std::istringstream iss(line);

            if (!std::getline(iss, date, '|'))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (!std::getline(iss, amount))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            date.erase(std::remove(date.end() - 1, date.end(), ' '), date.end());
            if(!amount.empty() && amount[0] == ' ')
                amount.erase(0,1);
            if (amount.begin() == amount.end() || date.begin() == date.end())
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            if (atof(amount.c_str()) < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (atof(amount.c_str()) > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            if (!is_all_digits(amount))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            std::string date_copy(date);
            date_copy.erase(std::remove(date_copy.begin(), date_copy.begin() + 10, '-'), date_copy.end());
            if (date[4] != '-' || date[7] != '-' || date.size() != 10)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (!is_all_digits(date_copy) || date_copy.size() != 8 || (date_copy[4] > '0' && date_copy[5] > '2') || (date_copy[6] >= '3' && date_copy[7] > '1') || (date_copy[4] == '0' && date_copy[5] == '0') || (date_copy[6] == '0' && date_copy[7] == '0'))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            value = B.price_on_date(date) * (float)atof(amount.c_str());
            if (value < 0)
            {
                std::cout << "Error: the date does not exist" << std::endl;
                continue;
            }

            std::cout << date << " => " << amount << " = " << value << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}