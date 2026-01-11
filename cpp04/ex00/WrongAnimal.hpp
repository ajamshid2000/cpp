/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:18:37 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:13:02 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &animal);
    WrongAnimal(const WrongAnimal &animal);

    void makeSound() const;
    std::string getType() const;
};

#endif
