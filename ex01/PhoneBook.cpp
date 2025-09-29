/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:30:02 by aboumall          #+#    #+#             */
/*   Updated: 2025/09/29 15:30:17 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

Contact *PhoneBook::GetContact(int index)
{
	if (index > 7 || index < 0 || this->index <= 0 || index >= this->index)
		return (Contact *)nullptr;
	return &this->contacts[index];
}
