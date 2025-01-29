/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:38:02 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/29 11:07:29 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <bits/stdc++.h>

class Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(Brain const& assign);
		~Brain();
	private:
		void	overthinkIdeas();
		void	printIdeas();
		std::string _ideas[100];
};