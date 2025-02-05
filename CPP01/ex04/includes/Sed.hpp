/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:01:59 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/03 10:48:25 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
	#define SED_HPP

# include <string>
# include <iostream>
# include <fstream>

class Sed
{
	public :
		Sed();
		void			open_copy(char	**av);
		~Sed();
	private :
		std::string		string_match(std::string full_str, std::string s1, std::string s2);
};

#endif