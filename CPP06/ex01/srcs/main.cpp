/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:41:05 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/01 16:41:38 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"
#include "../include/Serializer.hpp"

int main()
{
	Data *		data = new Data;
	uintptr_t	raw;

	std::cout << data << std::endl;

	raw = Serializer::serialize(data);

	std::cout << raw << std::endl;

	data = Serializer::deserialize(raw);

	std::cout << data << std::endl;

	delete data;
	return 0;
}