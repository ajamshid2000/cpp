/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:34:02 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/24 17:09:52 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
    for (int i = 0; i < 4; ++i)
    {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) : count(other.count)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.materias[i])
        {
            materias[i] = other.materias[i]->clone();
        }
        else
        {
            materias[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete materias[i];
            if (other.materias[i])
            {
                materias[i] = other.materias[i]->clone();
            }
            else
            {
                materias[i] = NULL;
            }
        }
        count = other.count;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (count < 4 && m)
    {
        materias[count] = m;
        count++;
        // std::cout << "materia learnt in slot " << count << std::endl;
    }
    else
    {
        delete m;
        std::cout << "Cannot learn more Materia (limit reached or null)" << std::endl;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < count; ++i)
    {
        if (materias[i] && materias[i]->getType() == type)
        {
            return materias[i]->clone();
        }
    }
    std::cout << "Materia of type " << type << " not found" << std::endl;
    return NULL;
}
