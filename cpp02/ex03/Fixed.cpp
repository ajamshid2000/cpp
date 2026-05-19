/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:46:11 by ajamshid          #+#    #+#             */
/*   Updated: 2024/12/13 17:55:37 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const int i) : fixed_point(i << this->fractional)
{
    // std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    fixed_point = f * (1 << this->fractional);
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    fixed_point = fixed.fixed_point;
    return *this;
}

bool	Fixed::operator>( const Fixed &that )
{
	return (this->fixed_point > that.fixed_point);
}

bool	Fixed::operator>=( const Fixed &that )
{
	return (this->fixed_point >= that.fixed_point);
}

bool	Fixed::operator<( const Fixed &that )
{
	return (this->fixed_point < that.fixed_point);
}

bool	Fixed::operator<=( const Fixed &that )
{
	return (this->fixed_point <= that.fixed_point);
}

bool	Fixed::operator==( const Fixed &that )
{
	return (this->fixed_point == that.fixed_point);
}

bool	Fixed::operator!=( const Fixed &that )
{
	return (this->fixed_point != that.fixed_point);
}

Fixed Fixed::operator+(const Fixed &fixed)
{
    return this->toFloat() + fixed.toFloat();
}

Fixed Fixed::operator-(const Fixed &fixed)
{
    return this->toFloat() + fixed.toFloat();
}

Fixed Fixed::operator/(const Fixed &fixed)
{
    return this->toFloat() / fixed.toFloat(); 
}

Fixed Fixed::operator*(const Fixed &fixed)
{
    return this->toFloat() * fixed.toFloat();
}

Fixed &Fixed::operator++()
{
    ++fixed_point;
    return *this;
}

Fixed &Fixed::operator--()
{
    --fixed_point;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++fixed_point;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --fixed_point;
    return temp;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1.fixed_point < fixed2.fixed_point)
        return fixed1;
    else
        return fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.fixed_point < fixed2.fixed_point)
        return fixed1;
    else
        return fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1.fixed_point < fixed2.fixed_point)
        return fixed2;
    else
        return fixed1;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.fixed_point < fixed2.fixed_point)
        return fixed2;
    else
        return fixed1;
}

Fixed::~Fixed()
{
    // std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
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
