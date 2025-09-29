/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:46:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/09/29 15:29:59 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include "vector"

#define nullptr 0

class PhoneBook
{
	private:
		Contact contacts[8];
		int	index;
	public:
		PhoneBook(Contact *contacts, int size);
		PhoneBook();
		void AddContact(Contact contact);
		Contact *GetContact(int index);
		Contact *GetContacts();
};

#endif