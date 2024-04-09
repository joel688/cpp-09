/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:54:24 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/09 10:18:46 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/PmergeMe/PmergeMe.hpp"

void printDeque(const std::deque<int>& _args) {
    std::deque<int>::const_iterator it;
    std::cout << "[";
    for (it = _args.begin(); it != _args.end(); ++it) {
        std::cout << *it;
        if (it != _args.end() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char **argv)
{
	PmergeMe test;
	for(int i = 1; i != argc; i++)
	{
		std::string arg = argv[i];

		if((!(arg == "shuf" && i == 1)) && !(arg == "-i" && i == 2) && !(arg == "-n" && i == 4))
		{
			if(test.checkArgs(argv[i]) == false)
			{
				std::cerr << "Error: bad arguments." << std::endl;
				std::cerr << "You send: " << arg << std::endl;
				std::cerr << "Arguments can only be a positive integer." << std::endl;
			}
		}
	}
	printDeque(test._args);
	while(!test._args.empty())
		test.buildSequences();
	test.buildFinalContainer();

	test.printMap();



}

