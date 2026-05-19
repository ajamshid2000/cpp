/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:11:58 by ajamshid          #+#    #+#             */
/*   Updated: 2024/12/13 17:53:37 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
    // std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x_float, const float y_float): x(Fixed(x_float)), y(Fixed(y_float))
{
    // std::cout << "constructor with parameter called" << std::endl;
}

Point::Point(const Point &point): x(point.x), y(point.y)
{
    // std::cout << "default copy consturctor called" << std::endl;
}

Point &Point::operator=(const Point &point)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    // std::cout << "Cannot be copied due to presence of const vars " << std::endl;
    std::terminate();
    (void)point;
    return *this;
}

Point::~Point()
{
    // std::cout << "Default destructor called" << std::endl;
}

float Point::get_x() const
{
    return (this->x.toFloat());
}

float Point::get_y() const
{
    return (this->y.toFloat());
}
