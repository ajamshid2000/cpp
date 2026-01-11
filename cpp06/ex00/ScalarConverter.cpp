/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:55:26 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/20 14:15:41 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits.h>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

bool ScalarConverter::isCharLiteral(const std::string &literal)
{
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isSpecialFloat(const std::string &literal)
{
    return literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool ScalarConverter::isSpecialDouble(const std::string &literal)
{
    return literal == "-inf" || literal == "+inf" || literal == "nan";
}

void ScalarConverter::convert(const std::string &literal)
{
    char *endptr = NULL;
    double dValue = 0.0;
    bool isChar = isCharLiteral(literal);
    bool isFloatSpec = isSpecialFloat(literal);
    bool isDoubleSpec = isSpecialDouble(literal);

    if (isChar)
    {
        dValue = static_cast<double>(literal[1]);
    }
    else if (isFloatSpec)
    {
        if (literal == "nanf")
            dValue = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            dValue = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            dValue = -std::numeric_limits<float>::infinity();
    }
    else if (isDoubleSpec)
    {
        if (literal == "nan")
            dValue = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            dValue = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            dValue = -std::numeric_limits<double>::infinity();
    }
    else
    {
        if (literal == "-nan" || literal == "-nanf")
        {
            std::cout << "the type conversion is impossible: please provide a valid number or char" << std::endl;
            return;
        }
        dValue = std::strtod(literal.c_str(), &endptr);
    }
    if (endptr == literal.c_str())
    {
        std::cout << "the type conversion is impossible: please provide a valid number or char" << std::endl;
        return;
    }

    // for characters
    std::cout << "char: ";
    if (std::isnan(dValue) || dValue < 0 || dValue > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(dValue)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(dValue) << "'" << std::endl;

    // for ints
    std::cout << "int: ";
    if (std::isnan(dValue) || dValue > static_cast<double>(INT_MAX) || dValue < static_cast<double>(INT_MIN))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(dValue) << std::endl;

    // for float numbers
    std::cout << "float: ";
    float f = static_cast<float>(dValue);
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // for double numbers
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << dValue << std::endl;
}
