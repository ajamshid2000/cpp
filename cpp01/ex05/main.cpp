/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:48:42 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/08 18:24:59 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl my_obj;

    my_obj.complain("debug");
    std::cout << "---------------------------------" << std::endl;
    my_obj.complain("info");
    std::cout << "---------------------------------" << std::endl;
    my_obj.complain("warning");
    std::cout << "---------------------------------" << std::endl;
    my_obj.complain("error");
    std::cout << "---------------------------------" << std::endl;
    my_obj.complain("err");
    return 0;
}
