/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:18:47 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/28 15:59:50 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <sstream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

	public:
		Contact(void);
		~Contact(void);

		void		ft_SetContact(std::string fn, std::string ln, 
			std::string nn, std::string pn, std::string ds);
		void		ft_DisplayContact(void) const;
		void		ft_SearchDisplay(int index);
		void		ft_Tronc(std::string str, bool pipe);
};

#endif