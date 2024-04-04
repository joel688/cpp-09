/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:56:56 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/04 10:07:53 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"

// ----------Constructors----------

Rpn::Rpn()
{
	return;
}

Rpn::Rpn(const Rpn& src) 
{
	*this = src;
	return;
}

// ----------Deconstructors----------

Rpn::~Rpn()
{
	return;
}

// ----------Setters----------

// ----------Getters----------

// ----------Operators_Overloaders----------

Rpn& Rpn::operator=(const Rpn& src)
{
	this->_operands = src._operands;
    return *this;
}

// ----------Members_Functions----------

double Rpn::evaluateRPN(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
	{
		if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
		{
            _operands.push_back(std::atof(token.c_str()));
        }
		else
		{
            if (_operands.size() < 2)
			{
                std::cerr << "Error" << std::endl;
                return 0;
			}
            double op2 = _operands.back();
            _operands.pop_back();
            double op1 = _operands.back();
            _operands.pop_back();

            switch (token[0])
			{
                case '+':
                    _operands.push_back(op1 + op2);
                    break;
                case '-':
                    _operands.push_back(op1 - op2);
                    break;
                case '*':
                    _operands.push_back(op1 * op2);
                    break;
                case '/':
                    _operands.push_back(op1 / op2);
                    break;
                default:
                    std::cerr << "Error" << token << std::endl;
                    return 0;
			}
        }
    }
	if (_operands.size() == 1)
	{
        double result = _operands.back();
        _operands.pop_back();
		std::cout << result << std::endl;
        return 0;
    }
	else
	{
        std::cerr << "Error" << std::endl;
        return 0;
    }
}

// ----------Non_Members_Functions----------


