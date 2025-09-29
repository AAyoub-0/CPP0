/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:42:19 by aboumall          #+#    #+#             */
/*   Updated: 2025/09/29 15:29:25 by aboumall         ###   ########.fr       */
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

#endif