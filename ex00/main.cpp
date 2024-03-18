/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:06 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/18 11:09:05 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/BitcoinExchange/BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if(argc != 2)
		throw BitcoinExchange::NoArgFileException();
	try
	{

		std::ifstream inputFile(argv[1]);
		btc->getLine(inputFile);
		
	}
	catch(BitcoinExchange::NoArgFileException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(BitcoinExchange::BadDateFormatException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(BitcoinExchange::BadValueException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(BitcoinExchange::BadLineFormatException &e)
	{
		std::cerr << e.what() << std::endl;
	}

}
