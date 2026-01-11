/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:39:28 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 14:49:11 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal *meta2 = new WrongAnimal();
    // const WrongAnimal* j = new Dog();
    const WrongAnimal *i2 = new WrongCat();
    // std::cout << j->getType() << " " << std::endl;
    std::cout << i2->getType() << " " << std::endl;
    i2->makeSound(); // will output the cat sound!
    // j->makeSound();
    meta2->makeSound();

    delete(meta);
    delete(j);
    delete(i);
    delete(meta2);
    delete(i2);

    return 0;
}
