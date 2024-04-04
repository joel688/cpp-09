/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:43:25 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/04 17:10:54 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <map>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

class PmergeMe 
{
	private:

	public:
		std::deque<int> _args;
		std::multimap<std::string, int> _sequences;
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		bool	checkArgs(char *arg);
		void	deleteInDeque(int i);
		void	addToMultiMap(int i);
		int		decreaseOrIncreaseSequence(void);
		void	buildSequences(void);

};

#endif
