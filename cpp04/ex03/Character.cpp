/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:39:18 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/24 17:57:16 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string n) : name(n)
{
    for (int i = 0; i < 4; ++i)
        slots[i] = NULL;
    node = new s_materias;
    node->next = NULL;
    node->to_be_freed = NULL;
}

Character::Character(const Character &other) : name(other.name)
{
    node = new s_materias;
    node->next = NULL;
    node->to_be_freed = NULL;
    for (int i = 0; i < 4; ++i)
    {
        if (other.slots[i])
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = NULL;
    }
}

Character::~Character()
{
    s_materias *temp;
    for (int i = 0; i < 4; ++i)
    {
        delete slots[i];
    }
    while (node->next)
    {
        temp = node->next;
        delete node->to_be_freed;
        delete node;
        node = temp;
    }
    delete node;
}

Character &Character::operator=(const Character &other)
{
    if (this == &other)
        return *this;
    for (int i = 0; i < 4; ++i)
    {
        delete slots[i];
        slots[i] = NULL;
    }
    name = other.name;
    for (int i = 0; i < 4; ++i)
    {
        if (other.slots[i])
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = NULL;
    }

    return *this;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!slots[i])
        {
            slots[i] = m;
            // std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    s_materias *temp;
    temp = node;
    while (temp->next)
        temp = temp->next;
    temp->to_be_freed = m;
    temp->next = new s_materias;
    temp->next->to_be_freed = NULL;
    temp->next->next = NULL;
    std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int index)
{
    s_materias *temp;
    temp = node;
    if (index >= 0 && index < 4 && slots[index])
    {
        // std::cout << "Unequipped " << slots[index]->getType() << " from slot " << index << std::endl;
        while (temp->next)
            temp = temp->next;
        temp->to_be_freed = slots[index];
        temp->next = new s_materias;
        temp->next->to_be_freed = NULL;
        temp->next->next = NULL;
        slots[index] = NULL;
    }
    else
    {
        std::cout << "Invalid slot or empty slot! cannot unequip" << std::endl;
    }
}

void Character::use(int index, ICharacter &target)
{
    if (index >= 0 && index < 4 && slots[index])
    {
        slots[index]->use(target);
    }
    else
    {
        std::cout << "Invalid slot or nothing equipped in slot " << index << std::endl;
    }
}
