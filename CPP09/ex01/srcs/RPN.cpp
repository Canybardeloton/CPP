/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:04 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/15 17:44:05 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

bool	checkDigits(const std::string& input)
{
	std::cout << input << std::endl;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != ' ')
			return (false);
		else if (isdigit(input[i]))
		{
			if (input[i] > 10)
				return (false);
		}
	}
	return (true);
}

bool	checkInput(const std::string& input)
{
	if (!checkDigits(input) || input.find("(") || input.find(")"))
		return (false);
	return (true);
}

std::stack<size_t>	getOperands(const std::string& input)
{
	std::stack<size_t> operands;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '+'&& input[i] == '-' && input[i] == '/' && input[i] == '*')
			operands.push(input[i]);
	}
	return (operands);
}

size_t	calculate(char operand, int num1, int num2)
{
	if (operand == '+')
		return (num1 + num2);
	else if (operand == '-')
		return (num1 - num2);
	else if (operand == '*')
		return (num1 * num2);
	else if (operand == '/')
		return (num1 / num2);
	return (0);
}

void	fillStack(const std::string& input)
{
	std::stack<char> numbers;
	std::stack<char> tmp;
	std::stack<size_t> operands;

	size_t	result = 0;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
			numbers.push(input[i]);
	}
	operands = getOperands(input);
	if (operands.empty())
	{
		std::cerr << "Error: no operands" << std::endl;
		return;
	}
	while (!operands.empty())
	{
		if (!isdigit(numbers.top()))
		{
			std::cerr << "Error: bad syntax" << std::endl;
			return;
		}
		tmp.push(numbers.top());
		numbers.pop();
		result = calculate(operands.top(), tmp.top(), numbers.top());
		operands.pop();
		numbers.pop();
		numbers.push(result);
	}
	std::cout << numbers.top() << std::endl;
}