/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:35:20 by ajamshid          #+#    #+#             */
/*   Updated: 2025/06/03 12:31:21 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::data;

BitcoinExchange::BitcoinExchange()
{
    std::string date, price, line;
    int num = 0;
    std::ifstream in_data("data.csv");
    if (!in_data)
        throw std::runtime_error("Error: could not open the data.csv");
    while (std::getline(in_data, line))
    {
        if (num == 0)
        {
            num = 1;
            continue;
        }
        std::istringstream iss(line);
        getline(iss, date, ',');
        getline(iss, price);
        data[date] = std::atof(price.c_str());
    }
    in_data.close();
}

BitcoinExchange::~BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

double BitcoinExchange::price_on_date(std::string date_given)
{
    std::map<std::string, double>::iterator it = data.find(date_given);

    if (it != data.end())
    {
        return it->second;
    }
    else
    {
        std::map<std::string, double>::iterator it = data.lower_bound(date_given);
        if (date_given > "2025-06-04" || it->first == "2009-01-02")
            return -1.0;
        else
        {
            --it;
            return it->second;
        }
    }
}