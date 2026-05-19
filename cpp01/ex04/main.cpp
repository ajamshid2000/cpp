/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:16:41 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/08 18:15:36 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    char in;
    int i;
    int j;
    std::string instring;
    std::ifstream infile;

    if (argc != 4)
    {
        std::cout << "please pass file_name S1 and S2 as arguments no more no less" << std::endl;
        return 0;
    }
    infile.open(argv[1]);

    while (infile.get(in))
        instring += in;
    infile.close();
    std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
    i = 0;
    while (instring[i])
    {
        j = instring.find(argv[2], i);
        if (j == i)
        {
            outfile << argv[3];
            i += std::string(argv[2]).size();
        }
        outfile << instring[i];
        i++;
    }
    outfile.close();
    return 0;
}