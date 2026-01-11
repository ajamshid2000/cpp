/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:14:48 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/24 16:29:18 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARECTER_HPP
#define ICHARECTER_HPP
#include <string>

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {}

    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int index) = 0;
    virtual void use(int index, ICharacter &target) = 0;
};

#endif