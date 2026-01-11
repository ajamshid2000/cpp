/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:20:03 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:13:15 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat();
    WrongCat &operator=(const WrongCat &cat);
    WrongCat(const WrongCat &cat);
};

#endif
