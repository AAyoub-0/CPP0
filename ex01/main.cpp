/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/08 00:45:28 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <sstream>
#include <iomanip>

#define BOLD "\033[1m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

static int ft_stoi(const std::string &str)
{
	std::istringstream iss(str);
	int num;
	iss >> num;
	if (iss.fail() || !iss.eof())
	{
		std::cerr << "Invalid input: " << str << std::endl;
		return -1;
	}
	return num;
}

static bool	check_line(std::string line)
{
	if (line.compare("ADD") != 0 && line.compare("SEARCH") != 0 && line.compare("EXIT") != 0)
	{
		std::cout << "Error: unknown command `" << line << "' . Please type ADD, SEARCH or EXIT" << std::endl;
		return (false);
	}
	return(true);
}

static void	print_contact(Contact contact, int index, int truncate)
{
	if (index < 0 || index > 8)
		return ;
	std::cout << BOLD << "Contact " << index << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "First Name " << ": " << GREY << contact.GetFirstName(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Last Name " << ": " << GREY << contact.GetLastName(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Phone Number " << ": " << GREY << contact.GetNum(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Nickname " << ": " << GREY << contact.GetNickname(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Darkest Secret " << ": " << GREY << contact.GetDarkestSecret() << RESET << std::endl;
}

static void	print_contact_tab(Contact contact, int index, int truncate)
{
	std::cout << BOLD << std::setw(5) << index << " | "
	          << std::setw(11) << contact.GetFirstName(truncate).substr(0, 10) << " | "
	          << std::setw(10) << contact.GetLastName(truncate).substr(0, 10) << " | "
	          << std::setw(10) << contact.GetNickname(truncate).substr(0, 10) << RESET << std::endl;
}

static void	print_header()
{
	std::cout << BOLD << std::setw(5) << "Index" << RESET << " | "
	          << std::setw(11) << "First Name" << " | "
	          << std::setw(10) << "Last Name" << " | "
	          << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
}

static void	print_contacts(PhoneBook *repertory)
{
	Contact *contacts = repertory->GetContacts();
	int i = 0;

	print_header();
	while (i < 8 && !contacts[i].GetNum(-1).empty())
	{
		print_contact_tab(contacts[i], i + 1, 10);
		i++;
	}
	if (i == 0)
		std::cout << "No contacts found." << std::endl;
	else 
		std::cout << std::string(45, '-') << std::endl;
}

static bool check_phone_number(const std::string &num)
{
	if (num.empty())
		return false;
	int i = 0;
	int size = 0;
	while (i < (int)num.length())
	{
		if (i == 0 && num[i] == '+')
		{
			i++;
			size++;
			continue;
		}
		if (!isdigit(num[i]) && !isspace(num[i]))
			return false;
		if (isdigit(num[i]))
			size++;
		i++;
	}
	if (size < 10 || size > 15)
		return false;
	return true;
}

static void	trait_command(std::string line, PhoneBook *repertory)
{
	int	i = 0;

	if (line.compare("ADD") == 0)
	{
		Contact contact;
		std::cout << BOLD<<"Adding new contact"<<RESET << std::endl;
		while (true)
		{
			line.clear();
			if (i == 0)
				std::cout << std::left << std::setw(16) << "First Name " << ": ";
			else if (i == 1)
				std::cout << std::left << std::setw(16) << "Last Name " << ": ";
			else if (i == 2)
				std::cout << std::left << std::setw(16) << "Nickname " << ": ";
			else if (i == 3)
				std::cout << std::left << std::setw(16) << "Phone Number " << ": ";
			else if (i == 4)
				std::cout << std::left << std::setw(16) << "Darkest Secret " << ": ";
			std::cout << GREY;
			getline(std::cin, line);
			if (std::cin.eof())
			{
				std::cout << std::endl;
				return ;
			}
			if (line.empty())
				continue ;
			if (i == 3)
			{
				if (!check_phone_number(line))
				{
					std::cout << RESET;
					std::cout << "Error: invalid phone number format. Please try again." << std::endl;
					continue ;
				}
			}
			std::cout << RESET;
			if (i == 0)
				contact.SetFirstName(line);
			else if (i == 1)
				contact.SetLastName(line);
			else if (i == 2)
				contact.SetNickname(line);
			else if (i == 3)
				contact.SetNum(line);
			else if (i == 4)
			{
				contact.SetDarkestSecret(line);
				break ;
			}
			i++;
		}
		repertory->AddContact(contact);
	}
	else if (line.compare("SEARCH") == 0)
	{
		print_contacts(repertory);
		std::cout << "Enter the index of the contact you want to see: ";
		if (getline(std::cin, line))
		{
			i = ft_stoi(line);
			print_contact(repertory->GetContact(i - 1), i, -1);
		}
		else
			std::cout << std::endl;
	}
	else if (line.compare("EXIT") == 0)
	{
		std::cout << "Exiting the phone book." << std::endl;
		exit(0);
	}
	else
	{
		std::cout << "Error: unknown command `" << line << "' . Please type ADD, SEARCH or EXIT" << std::endl;
	}
}

int	main()
{
	PhoneBook repertory;
	std::string line;

	while (true)
	{
		std::cout << BOLD << "> " << RESET;
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