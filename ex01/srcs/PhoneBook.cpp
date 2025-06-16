/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:01:49 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/28 14:24:45 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : OldessIndex(0), MaxSize(0)
{}

PhoneBook::~PhoneBook(void)
{}

void	PhoneBook::ft_AddContact(Contact &tmp)
{
	contacts[OldessIndex] = tmp;
	OldessIndex = (OldessIndex + 1) % 8;
	if (MaxSize < 8)
		MaxSize++;
}

void	PhoneBook::ft_Search(void)
{
	std::string	input;
	bool		IsNum = true;
	int			tmp;

	std::cout << std::endl;
	for (int i = 0; i < MaxSize; i++)
	{
		contacts[i].ft_SearchDisplay(i + 1);
	}
	std::cout << std::endl
			  << "Which contact you want to view (enter the index) : ";
	std::getline(std::cin, input);
	if (!std::cin)
	{
		if (std::cin.eof())
			std::cin.clear();
	}
	for (std::string::size_type j = 0; j < input.length() && IsNum; j++)
	{
		if (!isdigit(input[j]))
			IsNum = false;
	}
	if (IsNum)
	{
		std::cout << std::endl;
		tmp = std::atoi(input.c_str());
		if (tmp < 1 || tmp > MaxSize)
			std::cout << "Invalid index" << std::endl;
		else
			contacts[tmp - 1].ft_DisplayContact();
	}
	else
		std::cout << "Invalid index" << std::endl;
	std::cin.clear();
}
