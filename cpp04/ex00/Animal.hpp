/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:15:09 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:12 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();
    Animal &operator=(const Animal &animal);
    Animal(const Animal &animal);

    virtual void makeSound() const;
    std::string getType() const;
};

#endif
