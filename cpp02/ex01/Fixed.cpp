/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:46:11 by ajamshid          #+#    #+#             */
/*   Updated: 2024/12/13 13:58:38 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <tgmath.h>

// static float ft_pow(float base, int exp)
// {
//     float result;

//     if (!exp)
//         return (1);
//     if (exp < 0)
//     {

//         base = 1 / base;
//         exp *= -1;
//     }
//     result = base;
//     while (--exp)
//         result *= base;
//     return (result);
// }

Fixed::Fixed()
{
    std::cout << "Defaul constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const int i) : fixed_point(i << this->fractional)
{
    std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    fixed_point = f * (1 << this->fractional);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_point = fixed.fixed_point;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return (this->fixed_point / (float)(1 << this->fractional));
}

int Fixed::toInt(void) const
{
    return (this->fixed_point / (float)(1 << this->fractional));
}

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
    return (str << fixed_nbr.toFloat());
}
