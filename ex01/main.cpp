/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:30 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/18 18:46:27 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	*repertoire = new PhoneBook();
	Contact		*c1 = new Contact();
	Contact		*c2 = new Contact();
	Contact		*c3 = new Contact();

	repertoire->AddContact(*c1);
	repertoire->AddContact(*c2);
	repertoire->AddContact(*c3);
}