/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:12:24 by ajamshid          #+#    #+#             */
/*   Updated: 2025/06/03 17:48:28 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdlib.h>

RPN::RPN()
{
}
RPN::~RPN()
{
}
RPN::RPN(const RPN &other)
{
    this->stack = other.stack;
}
RPN &RPN::operator=(const RPN &other)
{
    this->stack = other.stack;
    return *this;
}

void RPN::do_operiation(char c)
{
    if (stack.size() >= 2)
    {

        int j = stack.top();
        stack.pop();
        int i = stack.top();
        stack.pop();
        switch (c)
        {
        case '+':
            stack.push(i + j);
            break;
        case '-':
            stack.push(i - j);
            break;
        case '*':
            stack.push(i * j);
            break;
        case '/':
            if (j == 0)
                throw std::runtime_error("Error");
            stack.push(i / j);
            break;
        }
    }
    else
        throw std::runtime_error("Error");
}

void RPN::calculate(char *str)
{
    std::istringstream iss(str);
    std::string token;
    while (iss >> token)
    {
        if (std::isdigit(token[0]) && token.size() == 1)
            stack.push(atoi(token.c_str()));
        else if (std::string("/*-+").find(token[0]) != std::string::npos && token.size() == 1)
            do_operiation(token[0]);
        else
            throw std::runtime_error("Error");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << stack.top() << std::endl;
}