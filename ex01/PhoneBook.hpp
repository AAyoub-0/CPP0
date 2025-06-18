/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:46:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/18 18:48:20 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"
#include "vector"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	index = 0;
	public:
		PhoneBook(Contact *contacts, int size);
		PhoneBook() = default;
		void AddContact(Contact contact);
};

PhoneBook::PhoneBook(Contact *contacts, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->contacts[index] = contacts[i];
		if (i < 7)
			index++;
	}
}

PhoneBook::PhoneBook() {}

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

#endif