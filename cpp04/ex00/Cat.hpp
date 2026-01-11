/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:15:09 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:34 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Animal.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    Cat &operator=(const Cat &cat);
    Cat(const Cat &cat);

    void makeSound() const;
};

#endif
