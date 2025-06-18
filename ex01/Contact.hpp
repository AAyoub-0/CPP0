/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:42:19 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/18 16:47:27 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	private:
		char	*first_name;
		char	*last_name;
		char	num[15];
	public:
		Contact(/* args */);
		~Contact();
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}


#endif