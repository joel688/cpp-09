/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:06 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/02 18:54:04 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/BitcoinExchange/BitcoinExchange.hpp"

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
	if(!inputCsv.is_open() || !inputTxt.is_open())
	{
		std::cout << btc.NoArgFiles() << std::endl;
		return 0;
	}
	btc.parseCsv(inputCsv);
	btc.parseIntput(inputTxt);
	btc.printResult();
	return 0;
}
