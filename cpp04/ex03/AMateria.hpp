/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:05:41 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/12 19:09:19 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string const type;

public:
    AMateria(std::string const &type);
    virtual ~AMateria() {}
    std::string const &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0; // this makes it a  pure abstract class so there is no need to have constructors or destructor because we cannot make an object of this class directly.
    virtual void use(ICharacter &target);
};

#endif