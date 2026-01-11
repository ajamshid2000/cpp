/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:50:47 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/20 13:42:26 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base(){}

Base *generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int i = (std::rand() % 3);
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
        return;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
        return;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
        return;
    }
    else
        std::cout << "unknown pointer type" << std::endl;
    return;
}
void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
    {
    }
    std::cout << "unknown referenct type" << std::endl;
}