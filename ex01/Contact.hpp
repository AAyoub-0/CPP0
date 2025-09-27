/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:42:19 by aboumall          #+#    #+#             */
/*   Updated: 2025/09/27 23:07:44 by aboumall         ###   ########.fr       */
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
		std::string nickname;
		std::string	num;
		std::string	darkest_secret;
	public:
		Contact(std::string num);
		Contact();
		std::string GetNum(int size);
		std::string GetFirstName(int size);
		std::string GetLastName(int size);
		std::string GetNickname(int size);
		std::string GetDarkestSecret();
		void SetNum(std::string num);
		void SetFirstName(std::string first_name);
		void SetLastName(std::string last_name);
		void SetNickname(std::string nickname);
		void SetDarkestSecret(std::string darkest_secret);
};

Contact::Contact(std::string num)
{
	this->num = num;
}

Contact::Contact() {}

std::string Contact::GetDarkestSecret() { return (this->darkest_secret); }

std::string Contact::GetNum(int size)
{
	if (size != -1)
	{
		if ((int)this->num.length() > size)
			return (this->num.substr(0, size - 1) + ".");
		return (this->num);
	}
	return (this->num);
}

std::string Contact::GetFirstName(int size)
{
	if (size != -1)
	{
		if ((int)this->first_name.length() > size)
			return (this->first_name.substr(0, size - 1) + ".");
		return (this->first_name);
	}
	return (this->first_name);
}

std::string Contact::GetLastName(int size)
{
	if (size != -1)
	{
		if ((int)this->last_name.length() > size)
			return (this->last_name.substr(0, size - 1) + ".");
		return (this->last_name);
	}
	return (this->last_name);
}

std::string Contact::GetNickname(int size)
{
	if (size != -1)
	{
		if ((int)this->nickname.length() > size)
			return (this->nickname.substr(0, size - 1) + ".");
		return (this->nickname);
	}
	return (this->nickname);
}

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

void Contact::SetNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::SetDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

#endif