/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/19 18:41:59 by aboumall         ###   ########.fr       */
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

static void	trait_command(std::string line, PhoneBook *repertory)
{
	Contact contact;
	int	i = 0;

	if (line.compare("ADD") == 0)
	{
		std::cout << "Adding new contact :" << std::endl;
		while (true)
		{
			char c;
			line.empty();
			if (i == 0)
				std::cout << "First Name: ";
			else if (i == 1)
				std::cout << "Last Name: ";
			else
				std::cout << "Phone Number: ";
			while (std::cin.get(c) && c != '\n')
			{
				if (c == 0)
					return ;
				if (i == 2)
				{
					if (!isdigit(c))
						std::cout << "\b \b";
					else
						line.push_back(c);
				}
				else
					line.push_back(c);
			}
			if (i == 0)
				contact.SetFirstName(line);
			else if (i == 1)
				contact.SetLastName(line);
			else
				contact.SetNum(line);
			i++;
			if (i > 2)
				break ;
		}
		repertory->AddContact(contact);
	}
	else if (line.compare("SEARCH") == 0)
	{
		contact = repertory->GetContact();
	}
}

int	main()
{
	PhoneBook repertory;
	std::string line;

	// (void)repertory;
	while (true)
	{
		std::cout << "Répertoire: ";
		if (!getline(std::cin, line))
		{
			std::cout << std::endl;
			break ;
		}
		if (!check_line(line))
			continue ;
		trait_command(line, &repertory);
		line.empty();
	}
}