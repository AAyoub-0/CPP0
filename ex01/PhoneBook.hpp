/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:46:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/07 23:51:25 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include "vector"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	index;
	public:
		PhoneBook(Contact *contacts, int size);
		PhoneBook();
		void AddContact(Contact contact);
		Contact GetContact(int index);
		Contact *GetContacts();
};

PhoneBook::PhoneBook() : index(0) {};

PhoneBook::PhoneBook(Contact *contacts, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->contacts[index] = contacts[i];
		if (i < 7)
			index++;
	}
}

Contact *PhoneBook::GetContacts()
{
	return this->contacts;
}

void PhoneBook::AddContact(Contact contact)
{
	if (index < 8) {
		this->contacts[index] = contact;
		index++;
	} else {
		index = 7;
		this->contacts[index] = contact;
	}
}

Contact PhoneBook::GetContact(int index)
{
	if (index > 7 || index < 0 || this->index <= 0)
	{
		std::cout << "Contact number" << index << "doesn't exist" << std::endl;
		return Contact();
	}
	return this->contacts[index];
}

#endif