/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:54:20 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:24:42 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"

#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
protected:
    std::string ideas[100];

public:
    Brain();
    ~Brain();
    Brain &operator=(const Brain &animal);
    Brain(const Brain &animal);
};

#endif
