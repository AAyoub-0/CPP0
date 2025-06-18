/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:46:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/18 16:44:17 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	index = 0;
	public:
		PhoneBook(Contact contacts[8]);
		~PhoneBook();
		void AddContact(Contact contact);
};

PhoneBook::PhoneBook(Contact *contacts)
{
	for (int i = 0; i < 8; i++)
	{
		this->contacts[i] = contacts[i];
		index++;
	}
}

PhoneBook::~PhoneBook() {}

void PhoneBook::AddContact(Contact contact)
{
	if (index < 8) {
		this->contacts[index] = contact;
		index++;
	} else {
		index = 8;
		this->contacts[index] = contact;
	}
}

#endif