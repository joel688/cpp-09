/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:06 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/03 16:47:29 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/BitcoinExchange/BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if(argc != 3)
	{
		std::cout << btc.NoArgFiles() << std::endl;
		return 0;
	}
	std::ifstream inputCsv(argv[1]);
	std::ifstream inputTxt(argv[2]);
	std::string	  isEmpty = argv[1];
	if(!inputCsv.is_open() || !inputTxt.is_open())
	{
		std::cout << btc.NoArgFiles() << std::endl;
		return 0;
	}
	if(btc.isCsvEmpty(isEmpty))
	{
		std::cout << "Error: empty Csv." << std::endl;
		return 0;
	}
	btc.parseCsv(inputCsv);
	btc.parseIntput(inputTxt);
	btc.printResult();
	return 0;
}
