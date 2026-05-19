/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:12:11 by ajamshid          #+#    #+#             */
/*   Updated: 2024/12/08 17:12:33 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CPP
#define POINT_CPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point &point);
    Point &operator=(const Point &point);
    ~Point();

    float get_x() const;
    float get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif