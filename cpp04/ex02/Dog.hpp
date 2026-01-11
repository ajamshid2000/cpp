/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:15:09 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:11:53 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog: public Animal
{
private:
    Brain *brain;
public:
    Dog();
    ~Dog();
    Dog &operator=(const Dog &dog);
    Dog(const Dog &dog);

    void makeSound() const;
};

#endif
