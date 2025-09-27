/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/09/28 00:39:20 by aboumall         ###   ########.fr       */
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
#define BLUE "\033[34m"
#define RESET "\033[0m"

static int ft_stoi(const std::string &str)
{
	std::istringstream iss(str);
	int num;
	iss >> num;
	if (iss.fail() || !iss.eof())
		return -1;
	return num;
}

static bool	check_line(std::string line)
{
	if (line.compare("ADD") != 0 && line.compare("SEARCH") != 0
		&& line.compare("EXIT") != 0)
	{
		std::cout << RED << "Error: unknown command"
		 "`" << RESET << line << RED << "' . Please type ADD, SEARCH or EXIT"
		 << RESET <<std::endl;
		return (false);
	}
	return(true);
}

static void	print_contact(Contact *contact, int index, int truncate)
{
	if (index < 0 || index > 8)
		return ;
	if (contact == nullptr)
	{
		std::cout << RED << "Error: contact not found." << RESET << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	std::cout << BOLD << "Contact " << index << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "First Name " << ": " << GREY << contact->GetFirstName(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Last Name " << ": " << GREY << contact->GetLastName(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Phone Number " << ": " << GREY << contact->GetNum(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Nickname " << ": " << GREY << contact->GetNickname(truncate) << RESET << std::endl;
	std::cout << std::left << std::setw(16) << "Darkest Secret " << ": " << GREY << contact->GetDarkestSecret() << RESET << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	std::cout << std::endl;
}

static void	print_contact_tab(Contact *contact, int index, int truncate)
{
	std::cout << BOLD << std::setw(5) << index << " | "
	          << std::setw(11) << contact->GetFirstName(truncate).substr(0, 10) << " | "
	          << std::setw(10) << contact->GetLastName(truncate).substr(0, 10) << " | "
	          << std::setw(10) << contact->GetNickname(truncate).substr(0, 10) 
			  << RESET << std::endl;
}

static void	print_header()
{
	std::cout << std::setw(5)  << "Index" 		<< " | "
	          << std::setw(11) << "First Name" 	<< " | "
	          << std::setw(10) << "Last Name" 	<< " | "
	          << std::setw(10) << "Nickname" 	<< std::endl;
	std::cout << std::string(45, '-') << std::endl;
}

static bool	print_contacts(PhoneBook *repertory)
{
	Contact *contact;
	int i = 0;

	std::cout << std::endl;
	if (repertory->GetContact(i) == nullptr)
	{
		std::cout << "No contacts found"
		<< GREY << " (use command ADD to create new ones)" << RESET << std::endl;
		std::cout << std::endl;
		return (false);
	}
	std::cout << BOLD << "Contacts List" << RESET << std::endl;
	print_header();
	while (i < 8)
	{
		contact = repertory->GetContact(i);
		if (contact == nullptr)
			break ;
		print_contact_tab(contact, i + 1, 10);
		i++;
	} 
	std::cout << std::string(45, '-') << std::endl;
	std::cout << std::endl;
	return (true);
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

static void	add_contact(std::string line, PhoneBook *repertory)
{
	int	i = 0;
	Contact contact;
	
	std::cout << BOLD << "Adding new contact" << RESET << std::endl;
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
		std::cout << RESET;
		if (i == 3)
		{
			if (!check_phone_number(line))
			{
				std::cout << RED << "Invalid phone number format."
					" Please try again with this format (+[Country code])[phone number]" 
					<< RESET << std::endl;
				continue ;
			}
		}
		else
		{
			if (line.empty())
			{
				std::cout << RED << "This field cannot be empty. "
				"Please try again." << RESET << std::endl;
				continue ;
			}
		}
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
			std::cout << std::endl;
			break ;
		}
		i++;
	}
	repertory->AddContact(contact);
}

static bool	search_contact(std::string line, PhoneBook *repertory)
{
	int	id = 0;

	if (!print_contacts(repertory))
		return (false);
	while (true)
	{
		std::cout 	<< "Enter the index of the contact you want to see " 
					<< GREY << "(or 0 to leave)" << RESET << ": ";
		if (getline(std::cin, line))
		{
			id = ft_stoi(line);
			if (id == 0)
				break ;
			if (id < 0 || id > 8)
			{
				std::cout << RED << "Error: invalid index. Please enter a number"
					" between 1 and 8." << RESET << std::endl;
				line.clear();
				continue ;
			}
			print_contact(repertory->GetContact(id - 1), id, -1);
			break ;
		}
		else
			std::cout << std::endl;
	}
	return (true);
}

static bool	trait_command(std::string line, PhoneBook *repertory)
{
	if (line.compare("ADD") == 0)
	{
		add_contact(line, repertory);
	}
	else if (line.compare("SEARCH") == 0)
	{
		if (!search_contact(line, repertory))
			return (true);
	}
	else if (line.compare("EXIT") == 0)
	{
		std::cout << "Exiting the phone book." << std::endl;
		return (false);
	}
	else
	{
		std::cout << RED << "Error: unknown command "
		"`" << RESET << line << RED << "' . Please type ADD, SEARCH or EXIT"
		   << RESET << std::endl;
	}
	return (true);
}

int	main()
{
	PhoneBook repertory;
	std::string line;

	std::cout << BOLD << GREEN << "Welcome to the Phone Book!" << RESET << std::endl;
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
		if (!trait_command(line, &repertory))
			break ;
		line.clear();
	}
}