/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:44:30 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/24 17:56:22 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main()
// {
//     IMateriaSource *src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter *me = new Character("me");
//     AMateria *tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter *bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete me;
//     delete src;
//     delete bob;
//     return 0;
// }

int main(void)
{
    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;
    std::cout << "/n--EQUIPPING AND UNEQUIPPING MULTIPLE TIMES TO CHECK FOR LEAKS--\n"
              << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));
    me->unequip(2);
    me->equip(src->createMateria("cure"));
    me->unequip(3);
    me->equip(new Ice());
    me->unequip(4);
    me->equip(src->createMateria("cure"));
        me->unequip(-1);
    std::cout << "/n--END OF EQUIPPING AND UNEQUIPPING MULTIPLE TIMES--\n"
              << std::endl;

    std::cout << "/n--CREATING MATERIAS THAT DOES NOT EXIST--\n"
              << std::endl;
    tmp = src->createMateria("NOT EXISTING MATERIA");
    tmp = src->createMateria("FIRE");
    tmp = src->createMateria("ICE");
    std::cout << "/n--END OF CREATING NON XISTING MATERIAS--\n"
              << std::endl;
    std::cout << "/n--TEST OF THE SUBJECT--\n"
              << std::endl;
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "/n--END OF TEST OF THE SUBJECT--\n"
              << std::endl;
    std::cout << "/n--TESTING COPY CONSTRUCTOR AND COPY ASSIGNEMENT OPERATOR OF CHARACTER--\n"
              << std::endl;

    Character *test = new Character("test");
    Character test2 = *test;
    test2 = *test;
    std::cout << test->getName() << std::endl;
    delete test;
    std::cout << test2.getName() << std::endl;
    std::cout << "/n--END OF TEST--\n"
              << std::endl;
    std::cout << "/n--DELETING ICHARACTER AND I MATERIA SOURCES--\n"
              << std::endl;
    delete bob;
    delete me;
    delete src;

    return 0;
}
