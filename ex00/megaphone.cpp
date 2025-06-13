/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:08:00 by aboumall          #+#    #+#             */
/*   Updated: 2025/06/13 16:32:34 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

char	to_upper_case(unsigned char c)
{
	return toupper(c);
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
    for (int i = 1; i < argc; ++i)
	{
		std::string text = argv[i];
		transform(text.begin(), text.end(), text.begin(), to_upper_case);
        std::cout << text;
		if (i + 1 < argc)
			std::cout << " ";
		else
			std::cout << std::endl;
    }

	return 0;
}
