/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:04 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/22 11:22:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

bool	checkDigits(const std::string& input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != ' ')
			return (false);
		else if (input[i] == ')' || input[i] == '(')
			return (false);
		else if (isdigit(input[i]))
		{
			if ((input[i] - '0') > 10)
				return (false);
		}
	}
	return (true);
}

bool	checkInput(const std::string& input)
{
	if (!checkDigits(input))
		return (false);
	return (true);
}

void processToken(std::stack<int>& numbers, char token)
{
	if (isdigit(token))
	{
		numbers.push(token - '0');
	}
	else if (token == '+' || token == '-' || token == '*' || token == '/')
	{
		if (numbers.size() < 2)
		{
			std::cerr << "Error: not enough operands for operator" << std::endl;
			exit(1);
		}
		int b = numbers.top();
		numbers.pop();
		int a = numbers.top();
		numbers.pop();

		int result = 0;
		switch (token)
		{
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/':
			if (b == 0)
			{
				std::cerr << "Error: division by zero" << std::endl;
				exit(1);
			}
			result = a / b;
			break;
		}
		numbers.push(result);
	}
}

void fillStack(const std::string& input)
{
	std::stack<int> numbers;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			continue;
		processToken(numbers, input[i]);
	}
	if (numbers.size() != 1)
	{
		std::cerr << "Error: invalid RPN expression" << std::endl;
		return;
	}
	std::cout << numbers.top() << std::endl;
}