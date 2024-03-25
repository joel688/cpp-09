/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:06 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/25 14:25:30 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tu add pas bien pour parseinput donc fait le bien

#include "./Class/BitcoinExchange/BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if(argc != 3)
		throw BitcoinExchange::NoArgFileException();
	try
	{

		std::ifstream inputFile(argv[1]);
		std::ifstream inputTxt(argv[2]);
		if(!inputFile.is_open() || !inputTxt.is_open())
			throw BitcoinExchange::NoArgFileException();
		btc.parseCsv(inputFile);
		btc.parseIntput(inputTxt);
		
	}
	catch(BitcoinExchange::NoArgFileException &e)
	{
		std::cerr << e.err() << std::endl;
	}
	
	return 0;
}
