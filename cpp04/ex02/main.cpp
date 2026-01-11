/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:39:28 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/24 17:49:57 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    int x;
    x = 0;
    std::cout << "\n-- CREATING ANIMAL ARRAY HALF DOG AND HALF CAT --\n" << std::endl;
    const Animal *array[20];
    while (x < 20)
    {
        if (x < (20 / 2))
            array[x] = new Dog();
        else
            array[x] = new Cat();
        x++;
    }

    std::cout << "\n-- EXECUTING MAIN OF THE SUBJECT --\n" << std::endl;
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j; // should not create a leak
    delete i;
    std::cout << "\n-- END OF MAIN OF THE SUBJECT --\n" << std::endl;
    std::cout << "\n-- TESTING COPYCONSTRUCTOR AND COPY ASSIGNEMENT OPERATOR--\n" << std::endl;
    Dog basic;
    Dog tmp = basic;
    Dog temp(basic);

    Cat basic2;
    Cat tmp2 = basic2;
    Cat temp2(basic2);
    std::cout << "\n-- END OF TEST --\n" << std::endl;
    std::cout << "\n-- DELETING ANIMAL ARRAY --\n" << std::endl;
    x = 0;
    while (x < 20)
        delete (array[x]), x++;
    // Animal test;

    return 0;
}
