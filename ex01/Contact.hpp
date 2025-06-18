/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:42:19 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/18 19:57:16 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string> 

class Contact
{
	private:
		std::string	first_name;
		std::string last_name;
		std::string	num;
	public:
		Contact(std::string num);
		Contact();
		std::string GetNum();
		std::string GetFirstName();
		std::string GetLastName();
		void SetNum(std::string num);
		void SetFirstName(std::string first_name);
		void SetLastName(std::string last_name);
};

Contact::Contact(std::string num)
{
	this->num = num;
}

Contact::Contact() {}

std::string Contact::GetNum() { return (this->num); }

std::string Contact::GetFirstName() { return (this->first_name); }

std::string Contact::GetLastName() { return (this->last_name); }

void Contact::SetNum(std::string num)
{
	this->num = num;
}

void Contact::SetFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::SetLastName(std::string last_name)
{
	this->last_name = last_name;
}

#endif