/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:54:24 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/09 11:30:46 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/PmergeMe/PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe Pmergeme;
	for(int i = 1; i != argc; i++)
	{
		std::string arg = argv[i];
		if((!(arg == "shuf" && i == 1)) && !(arg == "-i" && i == 2) && !(arg == "-n" && i == 4))
		{
			if(Pmergeme.checkArgs(argv[i]) == false)
			{
				std::cerr << "Error: bad arguments." << std::endl;
				std::cerr << "You send: " << arg << std::endl;
				std::cerr << "Arguments can only be a positive integer." << std::endl;
			}
		}
	}
	Pmergeme.printDeque();
	Pmergeme.buildSequences();
	Pmergeme.buildFinalContainer();
	Pmergeme.printMap();
}

