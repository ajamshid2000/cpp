/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:22:29 by ajamshid          #+#    #+#             */
/*   Updated: 2024/12/15 17:27:55 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << "TESTING CLAPTRAP\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << "Testing" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "Deconstructing" << std::endl;
	}
	std::cout << "TESTING SCAVTRAP\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		ScavTrap a;
		ScavTrap b("Savage");

		std::cout << "Testing" << std::endl;
		a.attack("CloneTrap");
		a.beRepaired(22);
		a.takeDamage(21);
		a.beRepaired(22);
		a.guardGate();
		a.guardGate();
		b.attack("Savage-clone");
		b.takeDamage(101);
		b.takeDamage(15);
		b.attack("ScavTrap-clone");
		std::cout << "Deconstructing" << std::endl;
	}
	std::cout << "\n\nTESTING FRAGTRAP\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		FragTrap a;
		FragTrap b("Chadd");

		std::cout << "Testing" << std::endl;
		a.highFivesGuys();
		a.attack("some random dude");
		a.takeDamage(101);
		a.takeDamage(1);
		a.attack("some random dude");
		b.highFivesGuys();
		std::cout << "[34mDeconstructing" << std::endl;
	}
	std::cout << "\n\nTESTING DIAMONDTRAP\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		DiamondTrap a;
		DiamondTrap b("Giga Chadd");
		DiamondTrap c(a);

		std::cout << "Testing" << std::endl;
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		c.whoAmI();
		std::cout << "Deconstructing"<< std::endl;
	}
	return (0);
}