/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:43:25 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/09 13:31:40 by joakoeni         ###   ########.fr       */
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
#include <algorithm>

class PmergeMe 
{
	private:
		std::deque<int> _args;
		std::multimap<int, int> _sequences;
		std::map<int, int> _final;

	public:
		int nb_sequence;
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		bool	checkArgs(char *arg);
		void	deleteInDeque(int i);
		void	addToMultiMap(int i);
		int		decreaseOrIncreaseSequence(void);
		void	buildSequences(void);
		void	buildFinalContainer(void);
		void	printMap(void);
		void	printDeque(void);
		int		sizeMap(void);
		int		sizeMultimap(void);
};

#endif
