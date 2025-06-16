/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:13:49 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/14 16:10:16 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <cstdlib>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		OldessIndex;
		int		MaxSize;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	ft_AddContact(Contact &contact);
		void	ft_Search(void);
};

#endif