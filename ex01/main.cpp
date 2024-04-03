/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:42:07 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/03 15:47:41 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/RPN/rpn.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
	{
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }
    std::string rpnExpression = argv[1];
    Rpn calculator;
    calculator.evaluateRPN(rpnExpression);
    return 0;
}
