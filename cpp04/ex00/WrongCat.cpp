/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:21:05 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:13:07 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"
#include <iostream>

    WrongCat::WrongCat()
    {
        std::cout << "default WrongCat constructor is called" << std::endl;
        type = "WrongCat";
    }
    WrongCat::~WrongCat()
    {
        std::cout << "default WrongCat destructor is called" << std::endl;
    }
    WrongCat &WrongCat::operator=(const WrongCat &cat)
    {
        std::cout << "default WrongCat copy assignement operator is called" << std::endl;
        this->type = cat.type;
        return *this;
    }
    WrongCat::WrongCat(const WrongCat &cat)
    {
        std::cout << "default WrongCat copy constructor is called" << std::endl;
        *this = cat;
    }

    // void WrongCat::makeSound() const
    // {
    //     std::cout << "WrongCat says meeeewwwww!" << std::endl;
    // }
