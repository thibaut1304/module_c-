/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:36:14 by thhusser          #+#    #+#             */
/*   Updated: 2022/04/19 21:54:33 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap player1("Thibaut"), player2("Marie");

	player1.attack("Marie");
	player2.takeDamage(2);

	player1.attack("Marie");
	player2.takeDamage(2);

	player1.attack("Marie");
	player2.takeDamage(2);

	player1.attack("Marie");
	player2.takeDamage(2);

	player2.beRepaired(1);

	player1.attack("Marie");
	player2.takeDamage(2);

	player1.attack("Marie");
	player2.takeDamage(3);
	player2.takeDamage(1);

	ClapTrap player3("test");

	ClapTrap player4 = player3;

	std::cout << "----------------------------------------------------------------\n" << std::endl;

	ScavTrap player5("Scavtrap_5");

	player5.attack("Marie");
	player5.guardGate();

	ScavTrap player6 = player5;

	return (0);
}
