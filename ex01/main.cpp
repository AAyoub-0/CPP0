/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/18 20:05:44 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static bool	check_line(std::string line)
{
	if (line.compare("ADD") != 0 && line.compare("SEARCH") != 0 && line.compare("EXIT") != 0)
	{
		std::cout << "Error: unknown command `" << line << "' . Please type ADD, SEARCH or EXIT" << std::endl;
		return (false);
	}
	return(true);
}

int	main()
{
	PhoneBook *repertoire = new PhoneBook();
	std::string line;

	(void)repertoire;
	while (true)
	{
		std::cout << "Répertoire: ";
		getline(std::cin, line);
		if (!check_line(line))
			continue ;
	}
}