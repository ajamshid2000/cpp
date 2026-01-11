/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:37:11 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/24 16:06:39 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

struct s_materias
{
    AMateria *to_be_freed;
    s_materias *next;
};


class Character : public ICharacter
{
private:
    std::string name;
    s_materias *node;
    AMateria *slots[4];

public:
    Character(const std::string n);
    Character(const Character &other);
    ~Character();
    Character &operator=(const Character &other);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int index);
    void use(int index, ICharacter &target);
};

#endif
