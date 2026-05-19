/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:45 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/23 14:48:31 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int i;

    i = 0;
    void (Harl::*functions[5])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    char levels[5][10] = {"debug", "info", "warning", "error", {'\0'}};
    while (level.compare(levels[i]) && i < 4)
        i++;
    if (level.compare(levels[i]))
    {
        std::cout << "level not found" << std::endl;
        return;
    }
    (this->*functions[i])();
}
