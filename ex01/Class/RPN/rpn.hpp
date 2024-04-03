/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:57:01 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/03 15:39:06 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cstdlib>

class Rpn
{
	private:
		std::list<double> _operands;

	public:
		Rpn();
    	~Rpn();
    	Rpn(const Rpn& src);
    	Rpn& operator=(const Rpn& src);
		double evaluateRPN(const std::string& expression);
    
};

#endif

